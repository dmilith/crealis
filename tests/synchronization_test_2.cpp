#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/progress.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

static bool _cont_ = false;
static unsigned int _delay_ = 5000000;
__thread int _i_;
__thread char _input_;
boost::mutex *mutex;
boost::mutex *mutex2;

void
thread_first() {
	boost::timer loop_timer;
	boost::xtime xt;
  
  while( true ) { 
    while( _cont_ ) {
      mutex->lock();
      
      cout << "1" << flush;
      boost::xtime_get( &xt, boost::TIME_UTC );
      xt.nsec += _delay_;
      boost::thread::sleep( xt );

      mutex2->unlock();
    }
    // when main thread body is suspended it should just wait for continuation
    boost::xtime_get( &xt, boost::TIME_UTC );
    xt.nsec += 50000000; // just slow down the loop
    boost::thread::sleep( xt );
  }
}


void
thread_second() {
	boost::timer loop_timer;
	boost::xtime xt;
  
  while( true ) {
    while( _cont_ ) {
      mutex2->lock();

      cout << "2" << flush;
      boost::xtime_get( &xt, boost::TIME_UTC );
      xt.nsec += _delay_;
      boost::thread::sleep( xt );

      mutex->unlock();
    }
    // when main thread body is suspended it should just wait for continuation
    boost::xtime_get( &xt, boost::TIME_UTC );
    xt.nsec += 50000000;
    boost::thread::sleep( xt );
  }
}


void
thread_third() {
  cout << "'r' to run, 's' to suspend, '+' to speed up, '-' to slow down, 'q' to quit.\n" << flush;
  while( true ) {
    cout << "@:" << flush;
    cin >> _input_;
    if ( _input_ == '+' ) _delay_ -= 1000000; // speed up
    if ( _input_ == '-' ) _delay_ += 1000000; // slow down
    if ( _input_ == 's' ) _cont_ = false; // stop
    if ( _input_ == 'r' ) _cont_ = true; // run
    if ( _input_ == 'q' ) {
      _cont_ = false;
      exit( 0 ); // the only way to quit(?)
    }

  }
}


int
main() {
    
    mutex = new boost::mutex();
    mutex2 = new boost::mutex();

    boost::thread first_thread( &thread_first );
    boost::thread second_thread( &thread_second );
    boost::thread third_thread( &thread_third );
    first_thread.join();
    second_thread.join();
    third_thread.join();
   
    // when doing << delete mutex >> it throws:
    // test_thread_synchronization_2: 
    // /usr/include/boost/thread/pthread/mutex.hpp:45: 
    // boost::mutex::~mutex(): Assertion `!pthread_mutex_destroy(&m)' failed.  
    // zsh: abort (core dumped)  ./test_thread_synchronization_2
    //
    // valgrind does not detect leaks.
	
  	return 0;
}

