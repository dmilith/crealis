
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

//Csoul souls[5000];


void
run() {
      boost::mutex mutex;

      Csoul *x = new Csoul();
      Csoul *y = new Csoul();
      
      x->set_mana( 1000 );
      y->set_mana( 995 );
      
      assert( x->get_mana() == 1000 );
      assert( y->get_mana() == 995 );

      Job *job = new Job();
      job->create_job( *x, *y, action_ATTACK );
      
      assert( job->get_actor( 0 ).get_mana() == 1000 );
      assert( job->get_actor( 1 ).get_mana() != 666 );

      boost::mutex::scoped_lock lock( mutex );
      job->run();
      
      assert( job->get_actor( 0 ).get_mana() < 1000 );
      assert( job->get_actor( 1 ).get_mana() == 995 );
    
      delete x;
      delete y;
      delete job;
}


int
main( int argc, char* argv[] ) {
  time_t start = time( NULL );
  boost::xtime xt;
  boost::thread_group threads;
   for ( int i = 0; i < 10000; ++i ) { /* on my machine 77824 is max, but 32760 is max after which boost_resource error
                                          is raised. ( cat /proc/sys/kernel/threads-max ) */
     threads.create_thread( &run );
  //   boost::xtime_get( &xt, boost::TIME_UTC );
  //   xt.nsec += 5000000; // just slow down the loop
  //   boost::thread::sleep( xt );

#ifdef DEBUG
     cout << "created thread " << i << endl << flush;
#endif

   }
#ifdef DEBUG
   cout << "Done. Quitting." << endl;
   cout << time( NULL ) - start << "seconds";
   assert( time( NULL) - start <= 10 );
#endif
   threads.join_all();
  return 0;
}


