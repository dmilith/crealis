
#include <iostream>
#include <cassert>
#include <fstream>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/progress.hpp>
#include <ctime>

#include "../../hashlib/hl_tools.h"
#include "../../coordinates.h"
#include "../../version.h"
#include "../../config.h"
#include "../../job.h"
#include "../../soul.h"


using namespace std;
using namespace core;


extern void create_job( Cobject* object0, Cobject* object1 );


#define DEBUG
#define VERBOSE


void
run() {
	boost::xtime xt;
  boost::mutex mutex;
  Csoul *x = new Csoul();
  Csoul *y = new Csoul();
    
    x->set_mana( 56700000 );
    y->set_mana( 12300000 );
    Job *job = new Job();
    job->create_job( *x, *y, action_ATTACK );
    
    cout << endl << job->get_actor( 0 ).get_mana() << flush << endl;
    assert( (uint64_t)job->get_actor( 0 ).get_mana() == (uint64_t)56700000 );
    assert( (uint64_t)job->get_actor( 1 ).get_mana() == (uint64_t)12300000 );

    boost::mutex::scoped_lock lock( mutex );
    job->run();
    
    boost::xtime_get( &xt, boost::TIME_UTC );
    xt.nsec += 5000; // just slow down the loop
    boost::thread::sleep( xt );
    
  delete x;
  delete y;
  delete job;
}


int
main( int argc, char* argv[] ) {
  time_t start = time( NULL );
  boost::thread_group threads;
   for ( int i = 0; i < 32000; ++i ) { /* on my machine 77824 is max, but 32760 is max after which boost_resource error
                                          is raised. ( cat /proc/sys/kernel/threads-max ) */
     threads.create_thread( &run );

#ifdef DEBUG
     cout << "created thread " << i << endl << flush;
#endif

   }
#ifdef DEBUG
   cout << "Done. Quitting." << endl;
   cout << time( NULL ) - start << "seconds";
#endif
   threads.join_all();
  return 0;
}


