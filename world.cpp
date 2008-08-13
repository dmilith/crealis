#include "world.h"
#include "version.h"

Cworld::Cworld() {
	//domyslne wartosci zmiennych
	xTheritorySize = DEFAULT_THERITORY_X;
	yTheritorySize = DEFAULT_THERITORY_Y;
	xPlaceSize = DEFAULT_PLACE_X;
	yPlaceSize = DEFAULT_PLACE_Y;
	gravity = DEFAULT_GRAVITY;
	version = systemClassesVersion;
};

Cworld::Cworld( unsigned int x, unsigned int y, double g ) { //maxX, maxY, grawitacja
	//wartosci szerokosci i wysokosci tabeli theritory swiata podane przez kreatora swiata
	xTheritorySize = x;
	yTheritorySize = y;
	xPlaceSize = DEFAULT_PLACE_X;
	yPlaceSize = DEFAULT_PLACE_Y;
	gravity = g;
	version = systemClassesVersion;
};

Cworld::Cworld( unsigned int x, unsigned int y, unsigned int x1, unsigned int y1, double g ) { //THmaxX, THmaxY, PLmaxY, PLmaxX grawitacja
	//wartosci szerokosci i wysokosci tabeli theritory swiata podane przez kreatora swiata
	xTheritorySize = x;
	yTheritorySize = y;
	xPlaceSize = x1;
	yPlaceSize = y1;
	gravity = g;
	version = systemClassesVersion; //z version.h
};

