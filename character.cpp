#include "character.h"


Ccharacter::Ccharacter() {
	name = "unnamed"; ///imie/nazwa postaci
	health = 100;
	intelligence = 0;
	strength = 0;
	dexterity = 0;
	luck = 0;
	mindStrength = 0; //cechy postaci
	race = human; //(0)
	
} //obiekt npc'a/ postaci gracza/ potwora

Ccharacter::Ccharacter( Eraces born_race ) {
	name = "unnamed"; ///imie/nazwa postaci
	health = 100;
	intelligence = 0;
	strength = 0;
	dexterity = 0;
	luck = 0;
	mindStrength = 0; //cechy postaci
	race = born_race; //(0)
	
} //obiekt npc'a/ postaci gracza/ potwora

