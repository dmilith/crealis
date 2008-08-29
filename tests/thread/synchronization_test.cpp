#include "../../hashlib/hl_tools.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/progress.hpp>
#include <boost/version.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

__thread int i;
boost::mutex mutex;
boost::mutex mutex2;


void
thread_first() {
	boost::timer loop_timer;
	boost::xtime xt;
  
  while( true ) {
    mutex.lock();
    
    cout << "." << flush;
    boost::xtime_get( &xt, boost::TIME_UTC );
		xt.nsec += 50000;
   	boost::thread::sleep( xt );
    generate_sha1();

    mutex2.unlock();
  }
}


void
thread_second() {
	boost::timer loop_timer;
	boost::xtime xt;
  
  while( true ) {
    mutex2.lock();

    cout << "#" << flush;
    boost::xtime_get( &xt, boost::TIME_UTC );
		xt.nsec += 50000;
   	boost::thread::sleep( xt );
    generate_sha1();

    mutex.unlock();
  }
}


int
main() {
    clock_t timer = clock();
    time_t timer_time = time( NULL );

    if ( BOOST_VERSION < 103500 ) {
      cout << "This project requires Boost 1.35!" << flush;
      exit( 0 );
    }

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

