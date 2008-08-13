#ifndef _CCOORDINATES_H_
#define _CCOORDINATES_H_

struct Sposition {
	signed int x,y;
};


class Ccoordinates {
public:
	Ccoordinates(); //zerowanie koordynatow -zeby nie bylo zadnych krzakow
	Sposition tCoord,pCoord; //territory x,y  place coord...
	char* mCoord; //nazwa mapy jako koordynat gdzie jestes
};

#endif //_CCOORDINATES_H_
