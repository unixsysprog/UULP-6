/* who1.c
   open, read UTMP file, and show results
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SHOWHOST
void showinfo(struct utmp *);

int main(int argc, char *argv[])
{
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);

    if((utmpfd=open(UTMP_FILE, O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(1);
    }

    while(read(utmpfd, &current_record, reclen) == reclen)
        showinfo(&current_record);
    close(utmpfd);
    return 0;
}

void showinfo(struct utmp *utbufp)
{
    printf("%-8.8s", utbufp->ut_name);
    printf(" ");
    printf("%-8.8s", utbufp->ut_line);
    printf(" ");
    printf("%10ld", utbufp->ut_time);
    printf(" ");
    #ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
    #endif
    printf("\n");
}
