/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "character.h"


Ccharacter::Ccharacter( std::string new_name ) {
	name = new_name; // creature name
	race = human; //(0)
	for ( int i = 0; i < 50; ++i ) {
		items[ i ] = NULL;
	}
	for ( int i = 0; i < 250; ++i ) {
		private_box[ i ] = NULL;
	}
	base_health = ( ( race * 100 ) + ( rand() % 10 ) ) + 100;
	health = base_health + ( rand() % 125 ) - 75; 
	dead = false;
	intelligence = ( ( rand() % 50 ) - ( race * 20 ) ) + 100  ;
	age = 10;
	strength = ( race * 2 ) + ( rand() % 10 ) + 3;
	dexterity = 0;
	luck = ( rand() % 21 ) - 10;
	mind_strength = 0; // creature properties

} // creature properties

Ccharacter::Ccharacter( Eraces born_race, std::string new_name ) {
	name = new_name;
	race = born_race; //(0)
	for ( int i = 0; i < 50; ++i ) {
		items[ i ] = NULL;
	}
	for ( int i = 0; i < 250; ++i ) {
		private_box[ i ] = NULL;
	}
	base_health = ( ( race * 100 ) + ( rand() % 10 ) ) + 100;
	health = base_health + ( rand() % 125 ) - 75 ;
	dead = false;
	intelligence = ( ( rand() % 50 ) - ( race * 20 ) ) + 100  ;
	age = 10 + ( rand() % 75 ); // it's poor to be old ;}
	strength = ( race * 2 ) + ( rand() % 10 ) + 3;
	dexterity = 0;
	luck = ( rand() % 21 ) - 10;
	switch( race ) {
		 case annimal:
				mind_strength = ( rand() % 10 ) + ( rand() % 3 ); //cechy postaci
				break;
		 case human:
				mind_strength = ( rand() % 35 ) + ( rand() % 3 ); //cechy postaci
				break;
		 case elve:
				mind_strength = ( rand() % 55) + ( rand() % 7 ); //cechy postaci
				break;
		 case dwarf:
				mind_strength = ( rand() % 45 ) + ( rand() % 3 ); //cechy postaci
				break;
		 case cave_troll:
				mind_strength = 120 + ( rand() % 75 ); //cechy postaci
				break;
		 case grizzly:
				mind_strength = 60 + ( rand() % 15 ); //cechy postaci
				break;
		 default:
					mind_strength = 100; //cechy postaci
					break;
	}
	
} //obiekt npc'a/ postaci gracza/ potwora

Ccharacter::~Ccharacter() {
/*	for ( int i = 0; i < 50; ++i ) {
		items[ i ] = NULL;
	}
	for ( int i = 0; i < 250; ++i ) {
		private_box[ i ] = NULL;
	}
	*/
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

