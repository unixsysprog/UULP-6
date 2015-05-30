/* play_again1.c 
   method: set tty into char-by-char mode
*/
#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

int get_response(char *);
void set_crmode();
int tty_mode(int);

int main(int argc, char *argv[])
{
    int response;
    tty_mode(0);
    set_crmode();
    response = get_response(QUESTION);
    tty_mode(1);
    return response;
}

int get_response(char *question)
{
    int input;
    printf("%s(y/n)?", question);
    while(1){
        switch(input = getchar()){
        case 'y':
        case 'Y':
            return 0;
        case 'n':
        case 'N':
        case EOF:
            return 1;
        default:
            printf("\ncannot understand %c, ", input);
            printf("Please type y or n \n");
        }
    }
}

void set_crmode()
{
    struct termios ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON; /* no buffering */
    ttystate.c_cc[VMIN] = 1;     /* get 1 char at a time */
    tcsetattr(0, TCSANOW, &ttystate);
}

int tty_mode(int how)
{
    static struct termios original_mode;
    if(how == 0){
        tcgetattr(0, &original_mode);
        return 0;
    }
    else
        return tcsetattr(0, TCSANOW, &original_mode);
}
