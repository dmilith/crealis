/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/
#ifndef _HL_TOOLS_H
#define _HL_TOOLS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
#include <sys/time.h>

#include "hashlibpp.h"

const char*
uint2cstr( uint64_t i );

std::string
generate_sha1();

#endif

