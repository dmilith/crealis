#ifndef _CITEM_H_
#define _CITEM_H_

#include "item.h"

enum Esize { tiny = 0, small, medium, large, outgenerous, huge };

class Citem {
public:
	Citem();
	unsigned int weight;
	Esize sizeOfItem;
		
};

#endif //_CBACKPACK_H_
