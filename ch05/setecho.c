/* setecho.c
   usage: setecho [y|n]
   shows: how to read, change reset tty attributes
 */
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct termios info;
    if(argc == 1)
        exit(0);
    if(tcgetattr(0, &info) == -1)
        perror("tcgetattr");
    if(argv[1][0] == 'y')
        info.c_lflag |= ECHO;
    else
        info.c_lflag &= ~ECHO;

    if(tcsetattr(0, TCSANOW, &info) == -1)
        perror("tcsetattr");
    return 0;
}
