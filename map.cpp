/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "map.h"

Cmap::Cmap() {
	name = "god's alley";	//map name		
	fileName = "god_s_alley"; //nazwa pliku mapy (bsp?)
} //mapa

Cmap::Cmap( std::string newName, std::string newFileName ) {
	name = newName;	//map name		
	fileName = newFileName; //nazwa pliku mapy
} //mapa
