/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CJOB_H_
#define _CJOB_H_

#include <iostream>
#include <string.h>

#include "character.h"
// TODO #include "world.h"
// TODO #include "map.h" 
#include "coordinates.h"

#include "hashlib/hl_tools.h"

enum ETypeOfJob {
			action_IDLE = 0,
			action_WALK = 1,
			action_RUN = 2,
			action_ATTACK = 10,
			action_DEFEND = 11,
};


class Job {
    public:
				Job();
			 	std::string job_id, job_crc; // sha1? -not yet implemented
				uint32_t job_flags; // specified flags for non-standard types of jobs -not yet implemented
				ETypeOfJob type;
				Ccharacter* actors[ 2 ]; // first is always main player, second one is optional
				void run();
};

#endif
