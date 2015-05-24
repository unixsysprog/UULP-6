/* who3.c - who with buffered reads
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SHOWHOST
void showtime(long);
void showinfo(struct utmp *);

int utmp_open(char *);
struct utmp * utmp_next();
void utmp_close();

int main(int argc, char *argv[])
{
    struct utmp *utbufp;

    if(utmp_open(UTMP_FILE) == -1){
        perror(UTMP_FILE);
        exit(1);
    }

    while((utbufp=utmp_next()) != ((struct utmp *)NULL))
        showinfo(utbufp);
    utmp_close();
    return 0;
}

void showinfo(struct utmp *utbufp)
{
    if(utbufp->ut_type != USER_PROCESS)
        return;
    printf("%-8.8s", utbufp->ut_name);
    printf(" ");
    printf("%-8.8s", utbufp->ut_line);
    printf(" ");
    showtime(utbufp->ut_time);
    #ifdef SHOWHOST
    if(utbufp->ut_host[0] != '\0')
        printf("(%s)", utbufp->ut_host);
    #endif
    printf("\n");
}

void showtime(long timeval)
{
    char *cp;
    cp = ctime(&timeval);
    printf("%12.12s", cp+4);
}
