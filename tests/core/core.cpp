/*

    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.

*/

/*
 * TODO:
 *
 */

#define DEBUG

#include "core.h"

using namespace std;
using namespace core;
using namespace boost;


//Ccore
Ccore::Ccore() {
  this->id = generate_sha1();
}


string
Ccore::get_core_version() {
  return CREALIS_CORE_VERSION;
}


string
Ccore::get_id() {
  return id;
}

void
Ccore::set_id( string id_ ) {
  this->id = id_;
}

bool
Ccore::is_changed() {
  return false;
}

uint32_t
Ccore::get_objects_amount() {
  // TODO create control file, with amount of objects and sha1 list of objects
  return 10; // FIXME temporarely !
}

//Cobject
Cobject::Cobject() {
  this->set_id( generate_sha1() );
  this->set_priority( 0 );
}

Cobject::Cobject( string id_ ) {
  this->set_id( id_ );
  this->set_priority( 0 );
}

Cobject::Cobject( int8_t priority_ ) {
  this->set_id( generate_sha1() );
  this->set_priority( priority_ );
}

Cobject::Cobject( string id_, int8_t priority_ ) {
  this->set_id( id_ );
  this->set_priority( priority_ );
}

void
Cobject::set_priority( int8_t priority_ ) {
  this->priority = priority_;
}

int8_t
Cobject::get_priority() {
  return this->priority;
}


bool
Cobject::save() {
  cout << "Saving " + this->get_id() << endl << flush;
  return true;
}

bool
Cobject::load( string filename_ ) {
  cout << "Loading " + filename_ << endl << flush;
  return true;
}

/*
 * main engine core
 */
int
main( int argc, char** argv ) {
  
  Ccore *core = new Ccore();
  cout << endl << "crealis root, core version " + core->get_core_version() <<
          ", classes version " << SYSTEM_CLASS_VERSION << endl << flush;
  cout << "root core id: " << core->get_id() << endl << flush;
  shared_array<Cobject> object_list( new Cobject[ core->get_objects_amount() ] );
  object_list[0].save();

  cout << "object core id: 0: " << object_list[0].get_id() << endl << flush;
  cout << "object core id: 1: " << object_list[1].get_id() << endl << flush;
  cout << "object core id: 2: " << object_list[2].get_id() << endl << flush;

  object_list[0].load( "zło" );
  cout << "Cobject size: " << sizeof( Cobject ) << endl << flush;

#ifdef DEBUG
  assert( sizeof( Cobject ) == sizeof( object_list[0] ) );
  assert( object_list[0].get_id() != object_list[1].get_id() );
  assert( object_list[1].get_id() != object_list[2].get_id() );
  assert( object_list != NULL );
  assert( core != NULL ); 
#endif
  delete core;
  return EXIT_SUCCESS;

}

