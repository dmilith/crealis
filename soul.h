/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CSOUL_H_
#define _CSOUL_H_

#include <iostream>

#include "core.h"

using namespace core;

enum Ealignment {
		chaoticEvil = 0,
		evil = 1,
		neutralEvil = 2,
		neutral = 3,
		neutralGood = 4,
		good = 5,
		lawfulGood = 6,
		demoan = 7 //demoan, polaczenie demona i aniola -cos jak chaoticNeutral
};

class Csoul : public Cobject {
  
  private:
	  
    uint64_t mana, /* mana */
             mind_strength; /* sila umyslu */
	  Ealignment alignment; //charakter
// XXX: it should be possible to 	  bool soul_exist; // does soul exist? - is it player or AI*
    
  public:
	  
    uint64_t get_mana();
    uint64_t get_mind_strength();
    void set_mana( uint64_t mana_ );
    void set_mind_strength( uint64_t mind_strength_ );

    Csoul();
	
};

#endif //_CSOUL_H_
