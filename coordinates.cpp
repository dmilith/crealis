#include "coordinates.h"
#include "hashlib/hashlibpp.h"


Ccoordinates::Ccoordinates() {
	hashwrapper *myWrapper = new sha1wrapper();
	position = "void";
	parent_positions[0] = "void";
	parent_positions[1] = "void";
	parent_positions[2] = "void";
	parent_positions[3] = "void";
	parent_positions[4] = "void";
	parent_positions[5] = "void";
	
}
