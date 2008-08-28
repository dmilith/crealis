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
	health = ( rand() % 125 ) - 75; 
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
	health = ( rand() % 125 ) - 75 ;
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
}


Ccharacter::~Ccharacter() {
}


void
Ccharacter::kill() {
#ifdef DEBUG
	std::cout << "Killed.";
	std::cout.flush();
#endif
	this->name = this->name + "(dead)";
	this->dead = true;
	// let character to stay in this world as living dead ;}
}


int32_t
Ccharacter::get_health() {
  return health;
}


std::string
Ccharacter::get_name() {
  return name;
}


uint32_t
Ccharacter::get_intelligence() {
  return intelligence;
}


uint32_t
Ccharacter::get_strength() {
  return strength;
}


uint32_t 
Ccharacter::get_dexterity() {
  return dexterity;
}


int32_t
Ccharacter::get_mind_strength() {
  return mind_strength;
}


int64_t
Ccharacter::get_gold() {
  return gold;
}


uint32_t
Ccharacter::get_age() {
  return age;
}


int16_t
Ccharacter::get_luck() {
  return luck;
}


Ccoordinates
Ccharacter::get_position() {
  return position;
}


void
Ccharacter::set_position( Ccoordinates position_ ) {
  position = position_;
}


Csoul*
Ccharacter::get_soul() {
  return soul;
}


void
Ccharacter::set_soul( Csoul* soul_ ) {
  soul = soul_;
}


Eraces
Ccharacter::get_race() {
  return race;
}


// TODO complete item getting/ putting
Citem
Ccharacter::get_item( uint8_t item_number_ ) {
}


void
Ccharacter::throw_item( Citem* item_ ) { // player is throwing away an item
  
}


void
Ccharacter::gain_item( Citem* item_ ) { // player is taking an item
}


void
Ccharacter::gain_health( int32_t damage_ ) { // get hurt or get heal
  health += damage_;
}


void
Ccharacter::gain_gold( int64_t gold_amount_ ) { // could be negative
  gold += gold_amount_;
}


void
Ccharacter::gain_dexterity( int64_t dexterity_ ) {
  dexterity += dexterity_;
}

void
Ccharacter::gain_strength( int64_t strength_ ) {
  strength += strength_;
}


void
Ccharacter::gain_intelligence( int64_t intelligence_ ) {
  intelligence += intelligence_;
}


void
Ccharacter::gain_luck( int16_t luck_ ) {
  luck += luck_;
}


bool
Ccharacter::is_dead() {
  return dead;
}


int32_t
Ccharacter::get_combat_ability() {
  return combat_ability;
}


int32_t
Ccharacter::get_armor() {
  return armor;
}


void
Ccharacter::gain_armor( int32_t armor_ ) {
  armor += armor_;
}


int32_t
Ccharacter::get_speed() {
  return speed;
}


void
Ccharacter::gain_speed( int32_t speed_ ) {
  speed += speed_;
}

void
Ccharacter::set_age( int16_t age_ ) {
  age = age_;
}


int32_t
Ccharacter::get_max_load() {
  return max_load;
}


void
Ccharacter::set_max_load( int32_t max_load_ ) {
  max_load = max_load_;
}

void
Ccharacter::set_name( std::string name_ ) {
  name = name_;
}
