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

};

class Ccharacter  {

private:	
  bool dead; // is character alive?
	std::string name;	// character's name
	Csoul* soul; // player's soul, when NULL then it's npc
	Eraces race;
	Citem* items[50];
	Citem* private_box[250];
	uint64_t gold;
	uint32_t age;
	int16_t luck; // luck could be negative

protected:
	int32_t
		  health,
			intelligence,
			strength,
			dexterity,
			mind_strength, // character attributes
      combat_ability, // const => born ability
      speed, // const => born ability
      armor,
      max_load;
	Ccoordinates position; // character's position

public:
	Ccharacter( std::string new_name = "A man" ); //domyslnie tworzony jest czlowiek
	Ccharacter( Eraces born_race, std::string new_name = "A man" ); //podajemy rase postaci
	~Ccharacter();
	
  void kill();
  int32_t get_health();
  std::string get_name();
  uint32_t get_intelligence();
  uint32_t get_strength();
  uint32_t get_dexterity();
  int32_t get_mind_strength();
  int64_t get_gold();
  uint32_t get_age();
  int32_t get_max_load();
  int16_t get_luck();
  int32_t get_combat_ability();
  int32_t get_armor();
  int32_t get_speed();
  Ccoordinates get_position();
  Csoul* get_soul();
  Eraces get_race();
  Citem get_item( uint8_t item_number_ );

  void gain_speed( int32_t speed_ );
  void set_age( int16_t age_ );
  void set_soul( Csoul* soul_ );
  void set_max_load( int32_t max_load_ );
  void gain_armor( int32_t armor_ );
  void gain_health( int32_t damage_ ); // get hurt or get heal
  void gain_gold( int64_t gold_amount_ ); // could be negative
  void gain_item( Citem* item_ ); // player is taking an item
  void throw_item( Citem* item_ ); // player is throwing away an item
  void gain_dexterity( int64_t dexterity_ );
  void gain_strength( int64_t strength_ );
  void gain_intelligence( int64_t intelligence_ );
  void gain_luck( int16_t luck_ );
  void set_position( Ccoordinates position_ );
  bool is_dead();

}; // player/ npc/ character

#endif //_CCHARACTER_H_

