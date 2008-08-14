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
				 std::cout << ( (Ccharacter*)this->actors.at( 0 ) )->health; // self only
				 fflush( stdout );
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
#ifdef DEBUG
	std::cout << "size:" << this->actors.size();
	fflush( stdout );
#endif
						if ( this->actors.size() < 2 ) break; // attack with no target? always must be attacker and someone to attack to
							( (Ccharacter*)this->actors.at( 0 ) )->health -= 3; // first is always attacking player	
					 		( (Ccharacter*)this->actors.at( 1 ) )->health -= 7; // always attacking at least one target
							
#ifdef DEBUG
	std::cout << "A=>" << this->actors.at( 0 )->health << std::endl;
	std::cout << "A=>" << this->actors.at( 1 )->health << std::endl;
	fflush( stdout );
#endif

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
