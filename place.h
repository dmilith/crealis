#ifndef _CPLACE_H_
#define _CPLACE_H_

#include <iostream>
#include <string.h>
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