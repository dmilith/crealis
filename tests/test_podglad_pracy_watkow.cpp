#include "../hashlib/hl_tools.h"
#include <boost/thread/thread.hpp>
#include <ncurses.h>

WINDOW  *mainWin,*vin1,*vin2;


char* itoa( int value, char* result, int base ) {
        
        if (base < 2 || base > 16) { 
                *result = 0; return result; 
        }
        
        char* out = result;     
        int quotient = value;
        
        do {    
                *out = "0123456789abcdef"[ std::abs( quotient % base ) ];
        
                ++out;
        
                quotient /= base;
        
        } while ( quotient );
        
        if ( value < 0 && base == 10) *out++ = '-';     
        std::reverse( result, out ); 
        *out = 0;       
        return result;
        
}

void
thread_first() {
        //cout<<"first_thread";
        char result [100];
        for ( int i = 0; i < 1000; i++ ) {
                wclear(vin1);      
                wprintw(vin1,"%d",itoa(i,result,10));                
                wrefresh(vin1);                               
                generate_sha1();
        }
}

void
thread_second() {

        //cout<<"second_thread";
        char result [100];
               
        for ( int i = 0; i < 100; i++ ) {
                                          
                wclear(vin2);
                wprintw(vin2,"%d",itoa(i,result,10));
                wrefresh(vin2);               
                generate_sha1();
        }
        
}

int main() {
        
        initscr();
        mainWin = newwin(0, 0, 0, 0);
        vin1 = subwin(mainWin, 20, 0, 0, 0);
        vin2 = subwin(mainWin, 5, 0, 20, 0);
        refresh();
        box(vin1, 0, 0);
        
        boost::thread first_thread( &thread_first );
        boost::thread second_thread( &thread_second );
        //first_thread.join();
        second_thread.join();
        
        getchar();
        delwin(mainWin);
        endwin();
        
        return 0;
}
