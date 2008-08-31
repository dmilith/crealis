/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "coordinates.h"

Ccoordinates::Ccoordinates() {
	strcpy( position, generate_sha1().c_str() );
	strcpy( parent_positions[ 0 ], generate_sha1().c_str() );
	strcpy( parent_positions[ 1 ], generate_sha1().c_str() );
	strcpy( parent_positions[ 2 ], generate_sha1().c_str() );
	strcpy( parent_positions[ 3 ], generate_sha1().c_str() );
	strcpy( parent_positions[ 4 ], generate_sha1().c_str() );
	strcpy( parent_positions[ 5 ], generate_sha1().c_str() );
}
  
char*
Ccoordinates::get_parent_position( uint8_t element_ ) {
  if ( element_ > 5 ) return NULL; // idiotouser check
  return parent_positions[ element_ ];
}

char*
Ccoordinates::get_position() {
  return position;
}

/*
Ccoordinates::Ccoordinates( char pos[SHA1_SIZE], char parent_pos[SHA1_SIZE][ 6 ] ) {
	strncpy( position,  pos, SHA1_SIZE );
	for ( int i = 0; i < 6; ++i ) {
		strncpy( parent_positions[ i ], parent_pos[ i ], SHA1_SIZE );
	}
}
*/
