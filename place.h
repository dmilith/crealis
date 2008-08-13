#ifndef _CPLACE_H_
#define _CPLACE_H_

#include "map.h"

class Cplace {
public:
	Cplace();
	Cplace(char* newName);
	char* name; //place name

	//MAP
	Cmap map; //mapa
}; //terytorium place'a

#endif //_CPLACE_H_
