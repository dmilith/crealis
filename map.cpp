#include "map.h"

Cmap::Cmap() {
	name="god's alley";	//map name		
	fileName="god_s_alley"; //nazwa pliku mapy (bsp?)
} //mapa

Cmap::Cmap(char* newName,char* newFileName) {
	name=newName;	//map name		
	fileName=newFileName; //nazwa pliku mapy (bsp?)
} //mapa
