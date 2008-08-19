/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CSOUL_H_
#define _CSOUL_H_

#include <iostream>

enum Ealignment {
		chaoticEvil = -3,
		evil = -2,
		neutralEvil = -1,
		neutral = 0,
		neutralGood = 1,
		good = 2,
		lawfulGood = 3,
		demoan = 4 //demoan, polaczenie demona i aniola -cos jak chaoticNeutral
};

class Csoul {
public:
	Csoul();
	uint64_t mana,
			mind_strength; //sila umyslu
	Ealignment alignment; //charakter
	
	bool soul_exist; //czy istnieje dusza. czyli czy postac jest graczem czy nie
	
};

#endif //_CSOUL_H_
