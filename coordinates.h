/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CCOORDINATES_H_
#define _CCOORDINATES_H_

#include "hashlib/hl_tools.h" //instead of haslibpp.h. It's kinda proxy for hashlib

static const uint8_t SHA1_SIZE = 41; // 40 + \0

class Ccoordinates {
public:
	Ccoordinates();
//  Ccoordinates( char pos[SHA1_SIZE], char parent_pos[SHA1_SIZE][ 6 ] );
  char position[SHA1_SIZE]; // sha1 as map location identifier
	char parent_positions[6][SHA1_SIZE]; // sha1 z sha sąsiadujących elementów liczone od lewego boku 6 kąta
};

#endif //_CCOORDINATES_H_
