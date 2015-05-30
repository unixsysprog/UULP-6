/* sleep1.c
   outline sets handler, sets alarm, pauses, then returns
 */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void wakeup(int);

int main(int argc, char *argv[])
{
    printf("about to sleep for 4 seconds\n");
    signal(SIGALRM, wakeup);
    alarm(4);
    pause();
    printf("Morning so soon?\n");
    return 0;
}

void wakeup(int signum)
{
    printf("Alarm received from kernel\n");
}
