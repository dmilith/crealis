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
	cout << "Core Init." << endl << flush;
}


Ccore::~Ccore() {
	cout << "Core UnInit." << endl << flush;
}


string
Ccore::get_core_version() {
  return CREALIS_CORE_VERSION;
#ifdef DEBUG
	cout << "GettingCoreVersion." << endl << flush;
#endif
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
  this->set_priority( 1 );
}


Cobject::Cobject( string id_ ) {
  this->set_id( id_ );
  this->set_priority( 1 );
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
  return this->id;
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


Ccoordinates
Cobject::get_position() {
  return this->position;
}


void
Cobject::set_position( Ccoordinates position_ ) {
  this->position = position_;
}


bool
Cobject::save_object() {
  COBJECT_DATA *temp = new COBJECT_DATA;
  strcpy( temp->id, ( this->get_id() ).c_str() );
  temp->priority = this->get_priority();
  temp->position = this->get_position();
#ifdef DEBUG
  cout << "Saving " + CORE_INFO_PATH + this->get_id() << endl << flush;
#endif  
    try {
      ofstream file( ( CORE_INFO_PATH + this->get_id() ).c_str(), ios_base::out | ios_base::binary );
      file.write( (char*)temp, sizeof( COBJECT_DATA ) );
      file.close();
    } catch (exception& e) {
      cout << e.what() << flush;
      exit( 1 );
    }
  delete temp;  
  return true;
}


Cobject
load_object( string filename_ ) {
  Cobject temp_obj;
  COBJECT_DATA *temp = new COBJECT_DATA;
#ifdef DEBUG
  cout << "Loading " + CORE_INFO_PATH + filename_ << endl << flush;
#endif
    try {
      ifstream file( ( CORE_INFO_PATH + filename_ ).c_str(), ios_base::in | ios_base::binary );
      file.read( (char*)temp, sizeof( COBJECT_DATA ) );
      file.close();
    } catch (exception& e) {
      cout << e.what() << flush;
      exit( 1 );
    }
  temp_obj.set_id( temp->id );
  temp_obj.set_priority( temp->priority );
  temp_obj.set_position( temp->position );
  delete temp;
  return temp_obj;
}


