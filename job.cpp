/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "job.h"


Job::Job() {
	job_id = generate_sha1( true );
	actors[ 0 ] = NULL;
	actors[ 1 ] = NULL;
}



void Job::run() {
#ifdef DEBUG
	std::cout << "R";
	std::cout.flush();
#endif
	 // matter on job type, do something with data
	 switch ( type ) {
			case action_IDLE:
#ifdef DEBUG
	 std::cout << "I:" << action_IDLE;
	 std::cout << this->actors[ 0 ]->name << ":" << this->actors[ 0 ]->health; // self only
	 std::cout.flush();
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
//	std::cout.flush();
#endif
						//if ( this->actors[ 1 ] ==  ) break; // attack with no target? always must be attacker and someone to attack to
						if ( this->actors[ 0 ]->health <= 0 ) {
#ifdef DEBUG
	std::cout << "A(0)h:0 ";
	std::cout.flush();
#endif
							 break;
						}
						if ( this->actors[ 0 ]->health <= 0 ) {
#ifdef DEBUG
	std::cout << "A(1)h:0 ";
	std::cout.flush();
#endif
							 break;
						}
						if ( this->actors[ 0 ]->dead ) {
#ifdef DEBUG
	std::cout << "#KDD, "; // killing a dead
	std::cout << this->actors[ 0 ]->name << ":" << this->actors[ 0 ]->health; // self only
	std::cout.flush();
#endif
							 break;
						}
						if ( this->actors[ 1 ]->dead ) {
#ifdef DEBUG
	std::cout << "#KDD, "; // killing a dead
	std::cout << this->actors[ 1 ]->name << ":" << this->actors[ 1 ]->health; // self only
	std::cout.flush();
#endif
							 break;
						}
						this->actors[ 0 ]->health -= 1; // first is always attacking player	
					 	this->actors[ 1 ]->health -= this->actors[ 0 ]->strength; // always attacking at least one target
						if ( this->actors[ 0 ]->health <= 0 ) {
								 this->actors[ 0 ]->kill();
#ifdef DEBUG
	std::cout << "DEAD0";
	std::cout.flush();
#endif
						}

						if ( this->actors[ 1 ]->health <= 0 ) {
									 this->actors[ 1 ]->kill();
#ifdef DEBUG
	std::cout << "DEAD1";
	std::cout.flush();
#endif
						}
#ifdef DEBUG
	std::cout << " A=>" << this->actors[ 0 ]->health << ", "; // << std::endl;
	std::cout << " B=>" << this->actors[ 1 ]->health << ", "; // << std::endl;
	std::cout.flush();
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
