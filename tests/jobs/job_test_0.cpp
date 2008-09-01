
#include <iostream>
#include <cassert>
#include <fstream>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include "../../hashlib/hl_tools.h"
#include "../../coordinates.h"
#include "../../version.h"
#include "../../config.h"
#include "../../job.h"
#include "../../soul.h"

using namespace std;
using namespace boost;
using namespace core;

extern void create_job( Cobject* object0, Cobject* object1 );

int main() {
  
  Csoul *x = new Csoul();
  Csoul *y = new Csoul();

  x->set_mana( 56700000 );
  y->set_mana( 12300000 );
  Job *job = new Job();
  job->create_job( *x, *y, action_ATTACK );
  job->run();
  cout << endl << job->get_actor( 0 ).get_mana() << flush << endl;
  assert( (uint64_t)job->get_actor( 0 ).get_mana() == (uint64_t)56700000 );
  assert( (uint64_t)job->get_actor( 1 ).get_mana() == (uint64_t)12300000 );

  Cobject myjob;
  myjob = job->get_actor( 0 );
  
  delete job;
  //delete x;
  //delete y;
  return 0;
}


