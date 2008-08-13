#include "map.h"

Cmap::Cmap() {
	name = "god's alley";	//map name		
	fileName = "god_s_alley"; //nazwa pliku mapy (bsp?)
} //mapa

Cmap::Cmap( std::string newName, std::string newFileName ) {
	name = newName;	//map name		
	fileName = newFileName; //nazwa pliku mapy
} //mapa
