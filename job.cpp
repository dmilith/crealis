#ifdef DEBUG
#include <iostream>
#include <string.h>
#endif

#include "job.h"
#include "character.h"
#include "config.h"


void Job::run() {
#ifdef DEBUG
	std::cout << "R";
	fflush( stdout );
#endif
	 // matter on job type, do something with data
	 switch ( type ) {
			case action_IDLE:
#ifdef DEBUG
	std::cout << "A:" << action_IDLE;
#endif
						break;
			case action_WALK:
#ifdef DEBUG
	std::cout << "A:" << action_WALK;
#endif
						break;
			case action_RUN:
#ifdef DEBUG
	std::cout << "A:" << action_RUN;
#endif
						break;
			case action_ATTACK:
//					 actors.at( 0 )->health = 53; // first is always attacking player	
	//				 actors.at( 1 )->health = 0; // always attacking at least one target


#ifdef DEBUG
	std::cout << "A:" << action_ATTACK;
#endif
						break;
			case action_DEFEND:
#ifdef DEBUG
	std::cout << "A:" << action_DEFEND;
#endif
						break;
			default: break;
	 }
}
