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
	Ccharacter( std::string new_name = "Zbigniew Żółć" ); //domyslnie tworzony jest czlowiek
	Ccharacter( Eraces born_race, std::string new_name = "Zbigniew Żółć" ); //podajemy rase postaci
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
			instinct, // instynkt im wyzszy tym postac bardziej potrafi wyczuc jakie ma szanse z przeciwnikiem :}
			mind_strength;//cechy postaci
	uint64_t gold;		
	uint32_t age; // wiek postaci
	int32_t luck; //szczescie moze byc -
	Ccoordinates pos; //pozycja postaci w swiecie
//	Cbackpack backpack; //plecak
	Csoul soul; // aktualna dusza :}
	Eraces race;
	//std::list<Citem> items;
	Citem items[50];
	Citem private_box[250];
}; //obiekt npc'a/ postaci gracza/ potwora

#endif //_CCHARACTER_H_
