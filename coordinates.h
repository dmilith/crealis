/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CCOORDINATES_H_
#define _CCOORDINATES_H_

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include "hashlib/hl_tools.h" //instead of haslibpp.h. It's kinda proxy for hashlib

class Ccoordinates {
public:
	Ccoordinates(); //zerowanie koordynatow -zeby nie bylo zadnych krzakow
	Ccoordinates( std::string pos, std::string parent_pos[ 6 ] );
	std::string position; // sha1 identyfikujące daną pozycję mapy
	std::string parent_positions[ 6 ]; // sha1 z sha sąsiadujących elementów liczone od lewego boku 6 kąta
};

#endif //_CCOORDINATES_H_
