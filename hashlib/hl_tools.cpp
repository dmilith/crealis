/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "hl_tools.h"


const char*
uint2cstr( uint64_t i ) {
  std::stringstream ss;
  std::string temp;
  ss << i;
  ss >> temp;
  return temp.c_str();
}

std::string
generate_sha1() {
	hashwrapper *sha1 = new sha1wrapper();
	std::string result = sha1->getHashFromString( 
      (std::string)( uint2cstr( ( (rand() % 100) * clock() ) + ( (rand() % (1 + rand()%100 ) ) ) ) ) );
	delete sha1;
	return result;
}


