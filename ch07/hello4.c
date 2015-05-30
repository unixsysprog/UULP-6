/* hello4.c 
   purpose show how to use erase, time, and draw for animation
*/
#include <unistd.h>
#include <stdio.h>
#include <curses.h>

int main(int argc, char *argv[])
{
    int i;
    initscr();
    clear();
    for(i=0; i<LINES; ++i){
        move(i, i+1);
        if(i%2 == 1)
            standout();
        addstr("Hello, world");
        if(i%2 == 1)
            standend();
        refresh();
        sleep(1);
        move(i, i+1);
        addstr("            ");
    }
    endwin();
    
    return 0;
}
