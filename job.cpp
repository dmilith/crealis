#include "job.h"
#include "character.h"
#include "config.h"

#ifdef DEBUG
#include <iostream>
#include <string.h>
#endif

Job::Job() {
	 this->actor = this->actors.end();
}

void Job::run() {
#ifdef DEBUG
	std::cout << "R";
	fflush( stdout );
#endif
	 // matter on job type, do something with data
	 switch ( type ) {
			case action_IDLE:
#ifdef DEBUG
	 std::cout << "I:" << action_IDLE;
	 std::cout << ( (Ccharacter*)this->actors.at( 0 ) )->name << ":" << ( (Ccharacter*)this->actors.at( 0 ) )->health; // self only
	 fflush( stdout );
#endif
						break;
			case action_WALK:
#ifdef DEBUG
	std::cout << "W:" << action_WALK;

#endif
						break;
			case action_RUN: // running away from monster for example
#ifdef DEBUG
	std::cout << "U:" << action_RUN;
#endif
						break;
			case action_ATTACK:
#ifdef DEBUG
//	std::cout << "(s:" << this->actors.size() << ")";
//	fflush( stdout );
#endif
						if ( this->actors.size() < 2 ) break; // attack with no target? always must be attacker and someone to attack to
						if ( (Ccharacter*)this->actors.at( 0 )->health <= 0 ) {
#ifdef DEBUG
	std::cout << "A(0)h:0 ";
	fflush( stdout );
#endif
							 break;
						}
						if ( (Ccharacter*)this->actors.at( 0 )->health <= 0 ) {
#ifdef DEBUG
	std::cout << "A(1)h:0 ";
	fflush( stdout );
#endif
							 break;
						}
						if ( (Ccharacter*)this->actors.at( 0 )->dead ) {
#ifdef DEBUG
	std::cout << "#KDD, "; // killing a dead
	std::cout << ( (Ccharacter*)this->actors.at( 0 ) )->name << ":" << ( (Ccharacter*)this->actors.at( 0 ) )->health; // self only
	fflush( stdout );
#endif
							 break;
						}
						if ( (Ccharacter*)this->actors.at( 1 )->dead ) {
#ifdef DEBUG
	std::cout << "#KDD, "; // killing a dead
	std::cout << ( (Ccharacter*)this->actors.at( 1 ) )->name << ":" << ( (Ccharacter*)this->actors.at( 1 ) )->health; // self only
	fflush( stdout );
#endif
							 break;
						}
						( (Ccharacter*)this->actors.at( 0 ) )->health -= 1; // first is always attacking player	
					 	( (Ccharacter*)this->actors.at( 1 ) )->health -= 
								 ( (Ccharacter*)this->actors.at( 0 ) )->strength ; // always attacking at least one target
						if ( ( (Ccharacter*)this->actors.at( 0 ) )->health <= 0 ) {
								( (Ccharacter*)this->actors.at( 0 ) )->kill();
#ifdef DEBUG
	std::cout << "DEAD0";
	fflush( stdout );
#endif
						}

						if ( ( (Ccharacter*)this->actors.at( 1 ) )->health <= 0 ) {
								( (Ccharacter*)this->actors.at( 1 ) )->kill();
#ifdef DEBUG
	std::cout << "DEAD1";
	fflush( stdout );
#endif
						}
#ifdef DEBUG
	std::cout << " A=>" << this->actors.at( 0 )->health << ", "; // << std::endl;
	std::cout << " B=>" << this->actors.at( 1 )->health << ", "; // << std::endl;
	fflush( stdout );
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
