/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

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
