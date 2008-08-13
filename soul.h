#ifndef _CSOUL_H_
#define _CSOUL_H_

enum Ealignment {
		chaoticEvil=-3,
		evil=-2,
		neutralEvil=-1,
		neutral=0,
		neutralGood=1,
		good=2,
		lawfulGood=3,
		demoan=4 //demoan, polaczenie demona i aniola -cos jak chaoticNeutral
};

class Csoul {
public:
	Csoul();
	unsigned int mana,
		     mindStrength; //sila umyslu
	Ealignment alignment; //charakter
	
	bool soulExist; //czy istnieje dusza. czyli czy postac jest graczem czy nie
	
};

#endif //_CSOUL_H_
