#ifndef _CBACKPACK_H_
#define _CBACKPACK_H_

#include <iostream>
#include "item.h"

class Cbackpack {
public:
	Cbackpack( Esize defaultSize );
	Esize sizeOfBackpack;
	uint32_t itemCount;
};

#endif //_CBACKPACK_H_
