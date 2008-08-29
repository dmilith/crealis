#include "../../hashlib/hl_tools.h"
#include <boost/thread/thread.hpp>
#include <iostream>
#include <ctime>


using namespace std;

void
thread_first() {
	cout << "first_thread\n" << flush;
  	for ( int i = 0; i < 1000000; i++ ) {  	
    		generate_sha1();
  	}
}

void
thread_second() {
	cout << "second_thread\n" << flush;
  	for ( int i = 0; i < 1000000; i++ ) {
    		generate_sha1();
  	}
}


int main() {
    clock_t timer = clock();
    time_t timer_time = time( NULL );

    boost::thread first_thread( &thread_first );
  	boost::thread second_thread( &thread_second );
  	first_thread.join();
  	second_thread.join();
    
    clock_t elapsed = ( clock() - timer ) / CLOCKS_PER_SEC;
    time_t elapsed_time = time( NULL ) - timer_time;
    cout << elapsed_time << " seconds" << endl << flush;
    cout << elapsed << " ticks (s)" << endl << flush;
	
  	return 0;
}
