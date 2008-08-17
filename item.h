#ifndef _CITEM_H_
#define _CITEM_H_

#include <iostream>

enum Esize { tiny = 0, small, medium, large, outgenerous, huge };

class Citem {
public:
	Citem();
	int64_t weight;
	Esize size_of_item;
		
};

#endif //_CITEM_H_
