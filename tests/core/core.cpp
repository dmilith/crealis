/*

    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.

*/

#define DEBUG

#include "core.h"

using namespace std;
using namespace core;


Ccore::Ccore() {
  id = generate_sha1();
}


string
Ccore::get_core_version() {
  return "0";
}


Cobject::Cobject() {
  set_id( generate_sha1() );
}

Cobject::~Cobject() {
}

string
Ccore::get_id() {
  return id;
}

void
Ccore::set_id( string id_ ) {
  id = id_;
}

bool
Ccore::is_changed() {
  return false;
}


int
main( int argc, char** argv ) {
  
  Ccore *core = new Ccore();
  cout << "root core id: " << core->get_id() << endl << flush;
  Cobject *obj = new Cobject();
  cout << "object core id: " << obj->get_id() << endl << flush;

#ifdef DEBUG
  assert( obj->get_id() != core->get_id() );
  assert( obj != NULL );
  assert( core != NULL ); 
#endif
  delete core;
  delete obj;
  return EXIT_SUCCESS;

}

