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

extern Cobject load_object( string filename_ );

/*
 * main engine core
 */
int
main( int argc, char** argv ) {
  
  Ccore *core = new Ccore();
  cout << endl << "crealis root, core version " + core->get_core_version() <<
          ", classes version " << SYSTEM_CLASS_VERSION << endl << flush;
  // create shared array with size MAX_OBJECTS_AMOUNT
  cout << "Initializing object list " << endl << flush;
  shared_array<Cobject> object_list( new Cobject[ core->get_max_objects_amount() ] );
  core->set_amount( 50 );

  if ( core->get_current_objects_amount() != 0 ) {
    object_list[ 0 ].save_object();

    cout << "object core id: 0: " << object_list[0].get_id() << endl << flush;
    cout << "object core id: 1: " << object_list[1].get_id() << endl << flush;
    cout << "object core id: 2: " << object_list[2].get_id() << endl << flush;
    cout << "object core id: 3: " << object_list[3].get_id() << endl << flush;
    object_list[1] = load_object( object_list[0].get_id() );
    
    cout << "object core [1], after reloading with object[0] " << object_list[1].get_id() << endl << flush;
    for ( int i = 0; i < 6; i++ ) {
      cout << object_list[1].get_position().get_parent_position( i ) << endl;
    }
    cout << "Cobject size: " << sizeof( Cobject ) << endl << flush;
  } else {
    cout << "object list empty." << endl << flush;
  }

#ifdef DEBUG
  assert( sizeof( Cobject ) == sizeof( object_list[0] ) );
  if ( core->get_current_objects_amount() > 2 ) {
    assert( object_list[0].get_id() == object_list[1].get_id() ); //cause we're reloading second object in object_list
    assert( object_list[1].get_id() != object_list[2].get_id() );
  }
  assert( object_list != NULL );
  assert( core != NULL ); 
#endif
  cout << endl << core->get_current_objects_amount() << endl;
  delete core;
  return EXIT_SUCCESS;
}

