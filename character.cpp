#include <stdlib.h>
#include "character.h"
#include "config.h"

#ifdef DEBUG
#include <iostream>
#include <string.h>
#endif


Ccharacter::Ccharacter() {
	name = "unnamed"; ///imie/nazwa postaci
	race = human; //(0)
	srand( (unsigned)time( NULL ) );
	base_health = ( ( race * 100 ) + ( rand() % 10 ) ) + 100;
	srand( (unsigned)time( NULL ) );
	health = base_health + ( rand() % 125 ) - 75; 
	dead = false;
	srand( (unsigned)time( NULL ) );
	intelligence = ( ( rand() % 50 ) - ( race * 20 ) ) + 100  ;
	age = 10;
	srand( (unsigned)time( NULL ) );
	strength = ( race * 2 ) + ( rand() % 10 ) + 3;
	dexterity = 0;
	srand( (unsigned)time( NULL ) );
	luck = ( rand() % 21 ) - 10;
	mind_strength = 0; //cechy postaci
	
} //obiekt npc'a/ postaci gracza/ potwora

Ccharacter::Ccharacter( Eraces born_race ) {
	name = "unnamed"; ///imie/nazwa postaci
	race = born_race; //(0)
	srand( (unsigned)time( NULL ) );
	base_health = ( ( race * 100 ) + ( rand() % 10 ) ) + 100;
	srand( (unsigned)time( NULL ) );
	health = base_health + ( rand() % 125 ) - 75 ;
	dead = false;
	srand( (unsigned)time( NULL ) );
	intelligence = ( ( rand() % 50 ) - ( race * 20 ) ) + 100  ;
	age = 10 + ( rand() % 75 ); // it's poor to be old ;}
	srand( (unsigned)time( NULL ) );
	strength = ( race * 2 ) + ( rand() % 10 ) + 3;
	dexterity = 0;
	srand( (unsigned)time( NULL ) );
	luck = ( rand() % 21 ) - 10;
	switch( race ) {
		 case annimal:
				srand( (unsigned)time( NULL ) );
				mind_strength = ( rand() % 10 ) + ( rand() % 3 ); //cechy postaci
				break;
		 case human:
				srand( (unsigned)time( NULL ) );
				mind_strength = ( rand() % 35 ) + ( rand() % 3 ); //cechy postaci
				break;
		 case elve:
				srand( (unsigned)time( NULL ) );
				mind_strength = ( rand() % 55) + ( rand() % 7 ); //cechy postaci
				break;
		 case dwarf:
				srand( (unsigned)time( NULL ) );
				mind_strength = ( rand() % 45 ) + ( rand() % 3 ); //cechy postaci
				break;
		 case cave_troll:
				srand( (unsigned)time( NULL ) );
				mind_strength = 120 + ( rand() % 75 ); //cechy postaci
				break;
		 case grizzly:
				srand( (unsigned)time( NULL ) );
				mind_strength = 60 + ( rand() % 15 ); //cechy postaci
				break;
		 default:
					mind_strength = 100; //cechy postaci
					break;
	}
	
} //obiekt npc'a/ postaci gracza/ potwora

Ccharacter::~Ccharacter() {
}

void Ccharacter::kill() {
#ifdef DEBUG
	std::cout << "Killed.";
	std::cout.flush();
#endif
	this->name = this->name + "(dead)";
	this->dead = true;
	// let character to stay in this world as living dead ;}
}

