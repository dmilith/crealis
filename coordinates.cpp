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

Ccoordinates::Ccoordinates() {
	hashwrapper *sha1 = new sha1wrapper();
	srand( (unsigned)time( NULL ) );
	position = sha1->getHashFromString( (std::string)( uint2cstr( rand() % time( NULL ) ) ) );
	parent_positions[0] = position;
	parent_positions[1] = "void";
	parent_positions[2] = "void";
	parent_positions[3] = "void";
	parent_positions[4] = "void";
	parent_positions[5] = "void";
	
}
