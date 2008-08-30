/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "coordinates.h"

Ccoordinates::Ccoordinates() {
	position = generate_sha1();
	parent_positions[ 0 ] = generate_sha1();
	parent_positions[ 1 ] = generate_sha1();
	parent_positions[ 2 ] = generate_sha1();
	parent_positions[ 3 ] = generate_sha1();
	parent_positions[ 4 ] = generate_sha1();
	parent_positions[ 5 ] = generate_sha1();
}

Ccoordinates::Ccoordinates( std::string pos, std::string parent_pos[ 6 ] ) {
	position = pos;
	for ( int i = 0; i < 6; ++i ) {
		parent_positions[ i ] = parent_pos[ i ];
	}
}
