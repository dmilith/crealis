#include "../../hashlib/hl_tools.h"
#include <boost/thread/thread.hpp>
#include <ncurses.h>

#define S_THREAD_FIRST  "Thread first -> counter %i"
#define S_THREAD_SECOND "Thread second -> counter %i"
#define S_HELP          "Press any key or x to abort tis app. !"

#define LINES_COUNT 1

WINDOW *win_1, *win_2, *win_help;

void
thread_first() {
        
        for ( int i = 0; i < 100000; i++ ) {
                
                wmove(win_1,0,0);
                wprintw(win_1, S_THREAD_FIRST, i);
                wrefresh(win_1);
                                             
                generate_sha1();
        }
}

void
thread_second() {
               
        for ( int i = 0; i < 100000; i++ ) {
                                          
                wmove(win_2,0,0);
                wprintw(win_2,S_THREAD_SECOND, i);
                wrefresh(win_2);
                
                generate_sha1();
        }
        
}

int main() {
        
        char c;
        unsigned int i = 0;
        
        initscr();
        noecho();
        refresh();
        
        win_1 = newwin(LINES_COUNT, COLS, 0, 0);
        win_2 = newwin(LINES_COUNT, COLS, LINES / 2 - LINES_COUNT / 2, 0);
        win_help = newwin(1, COLS, LINES - 1, 0);
        
        wprintw(win_help, S_HELP);
        wrefresh(win_help);
        
        boost::thread first_thread( &thread_first );
        //boost::thread second_thread( &thread_second );
        
        //first_thread.join();
        //second_thread.join();
        
        while((c = getch()) != 'x') {                
                
                wmove(win_2,0,0);
                wprintw(win_2,"%u", ++i);
                wrefresh(win_2);                                
        }
        
        //getchar();
        
        delwin(win_1);
        delwin(win_2);
        delwin(win_help);
        endwin();
        
        return 0;
}
