#ifndef _CCOORDINATES_H_
#define _CCOORDINATES_H_

#include <iostream>
#include <string.h>

struct Sposition {
	uint64_t x, y;
};


class Ccoordinates {
public:
	Ccoordinates(); //zerowanie koordynatow -zeby nie bylo zadnych krzakow
	Sposition tCoord,pCoord; //territory x,y  place coord...
	std::string mCoord; //nazwa mapy jako koordynat gdzie jestes
};

#endif //_CCOORDINATES_H_
