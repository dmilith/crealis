#include "../hashlib/hl_tools.h"
#include <boost/thread/thread.hpp>
#include <iostream>
#include <ncurses.h>

using namespace std;

WINDOW *vin;


char* itoa( int value, char* result, int base ) {
	
	if (base < 2 || base > 16) { 
		*result = 0; return result; 
	}
	
	char* out = result;	
	int quotient = value;
	
	do {	
		*out = "0123456789abcdef"[ abs( quotient % base ) ];
	
		++out;
	
		quotient /= base;
	
	} while ( quotient );
	
	if ( value < 0 && base == 10) *out++ = '-';	
	reverse( result, out );	
	*out = 0;	
	return result;
	
}

void
thread_first() {
	//cout<<"first_thread";
	char result [100];
  	for ( int i = 0; i < 1000; i++ ) {  	
  		wmove(vin,2,2);
    		wprintw(vin,itoa(i,result,10));
        	wrefresh(vin);
        	
    		generate_sha1();
  	}
}

void
thread_second() {

	//cout<<"second_thread";
	char result [100];
  	for ( int i = 0; i < 10000; i++ ) {
  		wmove(vin,0,0);
    		wprintw(vin,itoa(i,result,10));
        	wrefresh(vin);
    		generate_sha1();
  	}
}


int main() {
	
	initscr();
        vin=newwin(40,40,0,0);
        
  	boost::thread first_thread( &thread_first );
  	boost::thread second_thread( &thread_second );
  	first_thread.join();
  	//second_thread.join();
  	
        getchar();
        delwin(vin);
        endwin();
  	
  	return 0;
}
