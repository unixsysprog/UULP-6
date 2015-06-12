/* forkdemo3.c
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fork_rv;

    printf("Before: my pid is %d\n", getpid());

    fork_rv = fork();

    if(fork_rv == -1)
        perror("fork");
    else if(fork_rv == 0)
        printf("I an the child. my pid = %d\n", getpid());
    else
        printf("I an the parent. my child is %d\n", fork_rv);

    return 0;
}
