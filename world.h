/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/


#ifndef _CWORLD_H_
#define _CWORLD_H_

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/string.hpp>

#include "item.h"
#include "character.h"
#include "place.h"
#include "map.h"
#include "soul.h"
#include "coordinates.h"

// global consts
const uint32_t MAX_PLAYERS = 2000;
const uint32_t MAX_WORLDS = 50;
const uint32_t DEFAULT_GRAVITY = 0;
const uint32_t DEFAULT_THERITORY_X = 1;
const uint32_t DEFAULT_THERITORY_Y = 1;

// WORLD
class Cworld {
public:
	Cworld(); //domyslnie
	Cworld( std::string new_name, uint64_t x, uint64_t y, uint64_t g ); //podajemy rozmiar,i wartosc grawitacji
	uint64_t x_theritory_size, y_theritory_size; //rozmiary obszaru zdefiniowanego na serwerze (w theritoriach/place'ach))
	uint64_t gravity; //grawitacja
	std::string name;
	std::string cl_version; //wersja swiata. od tego zaleza ew niekompatybilnosci
};

#endif //_CWORLD_H_
