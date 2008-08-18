#include "coordinates.h"

const char*
uint2cstr( uint64_t i ) {
  std::stringstream ss;
  std::string temp;
  ss << i;
  ss >> temp;
  return temp.c_str();
}

std::string
generate_sha1( bool timeize_srand ) {
	hashwrapper *sha1 = new sha1wrapper();
	if ( timeize_srand ) srand( (unsigned)time( NULL ) );
	std::string result = sha1->getHashFromString( (std::string)( uint2cstr( rand() % time( NULL ) ) ) );
	delete sha1;
	return result;
}

Ccoordinates::Ccoordinates() {
	position = generate_sha1(true);
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
