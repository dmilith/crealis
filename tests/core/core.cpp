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


string
Ccore::get_core_version() {
  return CREALIS_CORE_VERSION;
}


Ccore::Ccore() {
  load_objects_amount();
}


Ccore::~Ccore() {
  save_objects_amount();
}

void
Ccore::save_objects_amount() {
  try {
    ofstream file( CORE_INFO_FILE.c_str(), ios_base::out | ios_base::binary );
    file.write( (char*)&objects_amount, sizeof( uint32_t ) );
    file.close();
  } catch (exception& e) {
    cout << e.what() << flush;
  }
}

void
Ccore::load_objects_amount() {
  try {
    ifstream file( CORE_INFO_FILE.c_str(), ios_base::in | ios_base::binary );
    file.read( (char*)&objects_amount, sizeof( uint32_t ) );
    file.close();
  } catch (exception& e) {
    cout << e.what() << flush;
  }
}


uint32_t
Ccore::get_current_objects_amount() {
  return objects_amount;
}


uint32_t
Ccore::get_max_objects_amount() {
  return MAX_OBJECTS_AMOUNT;
}

void
Ccore::set_amount( uint32_t value_ ) {
  this->objects_amount = value_;
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


bool
Cobject::is_changed() {
  return false;
}


string
Cobject::get_id() {
  return id;
}


void
Cobject::set_id( string id_ ) {
  this->id = id_;
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
    try {
      ofstream file( this->get_id().c_str(), ios_base::out | ios_base::binary );
      file.write( (char*)this, sizeof( Cobject ) );
      file.close();
    } catch (exception& e) {
      cout << e.what() << flush;
      exit( 1 );
    }
  return true;
}


Cobject
Cobject::load( string filename_ ) {
  Cobject temp;
  cout << "Loading " + filename_ << endl << flush;
    try {
      ifstream file( ( CORE_INFO_PATH + filename_ ).c_str(), ios_base::in | ios_base::binary );
      file.read( (char*)&temp, sizeof( Cobject ) );
      file.close();
    } catch (exception& e) {
      cout << e.what() << flush;
      exit( 1 );
    }
  return temp;
}


