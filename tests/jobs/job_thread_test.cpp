
#include <iostream>
#include <cassert>
#include <fstream>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>

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

  delete job;
}


int
main( int argc, char* argv[] ) {
  boost::thread_group threads;
   for (int i = 0; i < 1000000; ++i)
     threads.create_thread(&run);
   cout << "Running threads." << endl;
   threads.join_all();
  return 0;
}


