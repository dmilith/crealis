#include "world.h"
#include "version.h"

Cworld::Cworld() {
	//domyslne wartosci zmiennych

	this->name = "Somewhere in the bush";
	this->x_theritory_size = DEFAULT_THERITORY_X;
	this->y_theritory_size = DEFAULT_THERITORY_Y;
	this->gravity = DEFAULT_GRAVITY;
	this->cl_version = SYSTEM_CLASS_VERSION;
};

Cworld::Cworld( std::string new_name, uint64_t x, uint64_t y, uint64_t g ) { //maxX, maxY, grawitacja
	//wartosci szerokosci i wysokosci tabeli theritory swiata podane przez kreatora swiata
	this->x_theritory_size = x;
	this->y_theritory_size = y;
	this->gravity = g;
	this->cl_version = SYSTEM_CLASS_VERSION;
};


