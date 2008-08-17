#include "coordinates.h"
#include "hashlib/hashlibpp.h"
#include <algorithm>
#include <sstream>

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
	parent_positions[0] = generate_sha1();
	parent_positions[1] = generate_sha1();
	parent_positions[2] = generate_sha1();
	parent_positions[3] = generate_sha1();
	parent_positions[4] = generate_sha1();
	parent_positions[5] = generate_sha1();
}

