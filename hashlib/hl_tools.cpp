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
// C is so cooool.. i need to write 10 lines of code for one fucking random int
  time_t curtime;
  struct timeval tv;
  gettimeofday( &tv, NULL );
  curtime = tv.tv_usec + rand() % 10000000000;
	std::string result = sha1->getHashFromString( 
      (std::string)( uint2cstr( ( ( rand() % ( 1 + clock() ) * curtime ) + curtime ) ) ) );
	delete sha1;
	return result;
}


