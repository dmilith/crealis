#ifndef _CWORLD_H_
#define _CWORLD_H_

#include <vector>
#include <iostream>
#include <string.h>
#include "item.h"
#include "backpack.h"
#include "character.h"
#include "theritory.h"
#include "place.h"
#include "map.h"
#include "soul.h"
#include "coordinates.h"

#define MAX_PLAYERS 2000
#define DEFAULT_BACKPACK_SIZE 2 //medium
#define DEFAULT_GRAVITY 1.2
#define DEFAULT_THERITORY_X 1 // X theritory'w w jednej kolumnie world'a.. itd.. ;}
#define DEFAULT_THERITORY_Y 1 // Y theritory w jednym rzedzie world'a (czyli 1x1)
#define DEFAULT_PLACE_X 3 //X map na kolumne place'ow
#define DEFAULT_PLACE_Y 3 // Y map na rzad palce'ow ;} (czyli np dla X,Y=3 =>  3x3=9 map na therytory)
// domyslnych do mapy nie robimy, bo mapa moze miec dowolna (skalowalna) wielkosc..


// WORLD
class Cworld {
public:
	Cworld(); //domyslnie
	Cworld( unsigned int x, unsigned int y, double g ); //podajemy rozmiar,i wartosc grawitacji
	Cworld( unsigned int x, unsigned int y, unsigned int x1, unsigned int y1, double g ); //tu rozmiar w ther., rozmiar w place'ach, i grawitacja

	unsigned int xTheritorySize, yTheritorySize, xPlaceSize, yPlaceSize; //rozmiary obszaru zdefiniowanego na serwerze (w theritoriach/place'ach))

	std::vector<Ccharacter> character; //tablica postaci jako wektor

	double gravity; //grawitacja
	std::string name;

	//THERITORY
	Ctheritory theritory; //terytorium world'a
	std::string version; //wersja swiata. od tego zaleza ew niekompatybilnosci

	void load_world();
	void save_world();
};

#endif //_CWORLD_H_
