#ifndef _CCHARACTER_H_
#define _CCHARACTER_H_

#include "coordinates.h"
#include "backpack.h"
#include "soul.h"

enum Eraces {
	    human=0,
	    elve=1,
	    dwarf=2
			// ... dla kazdego przeciez klasy nie bede robil bo sie za*.*ie
};

class Ccharacter  {
public:
	Ccharacter(); //domyslnie tworzony jest czlowiek
	Ccharacter(Eraces race); //podajemy rase postaci
	char* name;	//imie/nazwa postaci
	unsigned char	
			intelligence,
			strength,
			dexterity,
			instinct, // instynkt im wyzszy tym postac bardziej potrafi wyczuc jakie ma szanse z przeciwnikiem :}
			mindStrength; //cechy postaci
	signed char luck; //szczescie moze byc -
	Ccoordinates pos; //pozycja postaci w swiecie
	Cbackpack backpack(Esize); //plecak
	Csoul soul; //dusza :}
	Eraces race;
		
}; //obiekt npc'a/ postaci gracza/ potwora

#endif //_CCHARACTER_H_
