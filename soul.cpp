/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "soul.h"

Csoul::Csoul() {
	mana = 10; //default value
	mind_strength = 0;	
	alignment = neutral;
}


uint64_t
Csoul::get_mana() {
  return this->mana;
}


uint64_t
Csoul::get_mind_strength() {
  return this->mind_strength;
}


void
Csoul::set_mana( uint64_t mana_ ) {
  this->mana = mana_;
}


void
Csoul::set_mind_strength( uint64_t mind_strength_ ) {
  this->mind_strength = mind_strength_;
}


