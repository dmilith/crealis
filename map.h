#ifndef _CMAP_H_
#define _CMAP_H_

#include <iostream>
#include <string.h>

class Cmap {
public:
	Cmap();
	Cmap( std::string newName, std::string newFileName );
	std::string name;	//map name		
	std::string fileName; // nazwa pliku bsp z mapa
}; //mapa

#endif //_CMAP_H_
