/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CPLACE_H_
#define _CPLACE_H_

#include <iostream>
#include <string>
#include "map.h"

class Cplace {
public:
	Cplace();
	Cplace( std::string newName );
	std::string name; //place name

	//MAP
	Cmap map; //mapa
}; //terytorium place'a

#endif //_CPLACE_H_
