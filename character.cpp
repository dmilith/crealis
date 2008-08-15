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
	strength = 0;
	dexterity = 0;
	luck = 0;
	mindStrength = 0; //cechy postaci
	
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
	age = 10;
	strength = 0;
	dexterity = 0;
	luck = 0;
	mindStrength = 0; //cechy postaci
	
} //obiekt npc'a/ postaci gracza/ potwora

Ccharacter::~Ccharacter() {
}

void Ccharacter::kill() {
#ifdef DEBUG
	std::cout << "Killed.";
	fflush( stdout );
#endif
	this->name = this->name + "(dead)";
//	this->health = 0;
	this->dead = true;
//	this->~Ccharacter();
}

