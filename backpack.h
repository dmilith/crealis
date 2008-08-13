#ifndef _CBACKPACK_H_
#define _CBACKPACK_H_

#include "item.h"

class Cbackpack {
public:
	Cbackpack(Esize defaultSize);
	Esize sizeOfBackpack;
	char itemCount;
};

#endif //_CBACKPACK_H_
