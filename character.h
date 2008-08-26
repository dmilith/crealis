/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CCHARACTER_H_
#define _CCHARACTER_H_


#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include "coordinates.h"
#include "item.h"
#include "soul.h"
#include "config.h"

const uint32_t MAX_HUMAN_AGE = 115;
const uint32_t MAX_ELVE_AGE = 2000;
const uint32_t MAX_DWARF_AGE = 350;

enum Eraces {
	    annimal = 0,
	    elve = 1,
	    human = 2,
			dwarf = 3,
	    grizzly = 4,
			cave_troll = 25

			// ... dla kazdego przeciez klasy nie bede robil bo sie za*.*ie
};

class Ccharacter  {
public:
	Ccharacter( std::string new_name = "Zbigniew Zolc" ); //domyslnie tworzony jest czlowiek
	Ccharacter( Eraces born_race, std::string new_name = "Zbigniew Zolc" ); //podajemy rase postaci
	~Ccharacter();
	bool dead;
	void kill();

	std::string name;	//imie/nazwa postaci
	int64_t
			base_health,
		  health,
			intelligence,
			strength,
			dexterity,
			mind_strength;//cechy postaci
	uint64_t gold;		
	uint32_t age; // wiek postaci
	int16_t luck; //szczescie moze byc -
	Ccoordinates position; //pozycja postaci w swiecie
	Csoul soul; // aktualna dusza :}
	Eraces race;
	Citem* items[50];
	Citem* private_box[250];
}; //obiekt npc'a/ postaci gracza/ potwora

#endif //_CCHARACTER_H_
