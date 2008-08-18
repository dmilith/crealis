#ifndef _CJOB_H_
#define _CJOB_H_

#include <iostream>
#include <string.h>

#include "character.h"

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
			 	std::string job_id; // sha1? -not yet implemented
				uint32_t job_flags; // specified flags for non-standard types of jobs -not yet implemented
				ETypeOfJob type;
				Ccharacter actors[ 2 ]; // first is always main player, second one is optional
				void run();
};

#endif
