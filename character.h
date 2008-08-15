#ifndef _CCHARACTER_H_
#define _CCHARACTER_H_

#include <iostream>
#include <string.h>
#include "coordinates.h"
#include "backpack.h"
#include "soul.h"

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
	Ccharacter(); //domyslnie tworzony jest czlowiek
	Ccharacter( Eraces born_race ); //podajemy rase postaci
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
	uint32_t age; // wiek postaci
	int32_t luck; //szczescie moze byc -
	Ccoordinates pos; //pozycja postaci w swiecie
	Cbackpack backpack( Esize ); //plecak
	Csoul soul; // aktualna dusza :}
	Eraces race;
  // TODO: Citem. 
	// Citem weapon1, weapon2;
}; //obiekt npc'a/ postaci gracza/ potwora

#endif //_CCHARACTER_H_
