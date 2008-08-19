/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

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
