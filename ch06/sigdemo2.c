/* sigdemo2.c */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    signal(SIGINT, SIG_IGN);
    printf("you can't stop me!\n");
    while(1){
        sleep(1);
        printf("haha\n");
    }
}
