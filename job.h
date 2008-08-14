#ifndef _CJOB_H_
#define _CJOB_H_

#include <iostream>
#include <string.h>
#include <vector>

#include "character.h"

enum CTypeOfJob {
			action_IDLE = 0,
			action_WALK = 1,
			action_RUN = 2,
			action_ATTACK = 10,
			action_DEFEND = 11,						
};


class Job {
    public:
				std::string job_info;
				std::string job_data;
				CTypeOfJob type;
				std::vector<Ccharacter*> actors; // first is always main player
				
				void run();
};

#endif
