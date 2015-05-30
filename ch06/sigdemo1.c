/* sigdemo1.c */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void f(int);

int main(int argc, char *argv[])
{
    int i;
    signal(SIGINT, f);
    for(i=0; i<5; ++i){
        printf("hello\n");
        sleep(1);
    }
    return 0;
}

void f(int signum)
{
    printf("OUCH!\n");
}
