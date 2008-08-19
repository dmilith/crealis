/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CTHERITORY_H_
#define _CTHERITORY_H_

#include <iostream>
#include <string>
#include "place.h"

//THERITORY
class Ctheritory {
public:
	Ctheritory();
	std::string name; //theritory name and/or sha1 identifier
	//PLACE
	Cplace place; //terytorium place'a

}; //terytorium world'a

#endif //_CTHERITORY_H_
