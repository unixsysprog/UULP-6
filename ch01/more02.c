/* more02.c
   read and print 24 lines then pause for a few special commands
   reads from /dev/tty for commands
 */
#include <stdio.h>
#include <stdlib.h>
#define PAGELEN 24
#define LINELEN 512

void do_more(FILE *);
int see_more(FILE *);

int main(int argc, char *argv[])
{
    FILE *fp;
    if(argc == 1)
        do_more(stdin);
    else
        while(--argc)
            if((fp=fopen(* ++argv, "r")) != NULL){
                do_more(fp);
                fclose(fp);
            }
            else
                exit(1);
    return 0;
}

void do_more(FILE *fp){
    char line[LINELEN];
    int num_of_lines = 0;
    int reply;
    FILE *fp_tty = fopen("/dev/tty", "r");
    if(fp_tty == NULL)
        exit(1);
    while(fgets(line, LINELEN, fp)){ /* read in one line */
        if(num_of_lines == PAGELEN){ /* if the screen is full */
            reply = see_more(fp_tty); /* ask user */
            if(reply == 0)
                break;
            num_of_lines -= reply;
        }
        if(fputs(line, stdout) == EOF) /* show one line */
            exit(1);
        num_of_lines++;
    }
}

int see_more(FILE * cmd){
    /* q means no, space means one screen, CR means one line */
    int c;
    printf("\033[7m more? \033[m");
    while((c=getc(cmd)) != EOF){
        if(c == 'q')
            return 0;
        if(c == ' ')
            return PAGELEN;
        if(c == '\n')
            return 1;
    }
    return 0;
}
