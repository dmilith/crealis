/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "job.h"


Job::Job() {
	job_id = generate_sha1();
  job_flags = 0;
}


Job::~Job() {
}


void
Job::create_job( Cobject& object0_, Cobject& object1_, ETypeOfJob action_ ) {
  actor0 = (const Csoul&)object0_;
  actor1 = (const Csoul&)object1_;
  set_action( action_ );
}


Csoul&
Job::get_actor( uint8_t actor_num_ ) {
  if ( actor_num_ == 0 ) 
    return actor0;
  else
    return actor1;
}


void
Job::set_action( ETypeOfJob type_ ) {
  this->type = type_;
}


void
Job::run() {
// matter on job type, do something with data
	 switch ( type ) {
			case action_IDLE:
#ifdef DEBUG
	cout << "I:" << action_IDLE << flush;
#endif
			break;
			case action_WALK:
#ifdef DEBUG
	cout << "W:" << action_WALK << flush;
#endif
			break;
			case action_RUN: // running away from monsters for example
#ifdef DEBUG
	cout << "U:" << action_RUN << flush;
#endif
			break;
			case action_ATTACK:
        get_actor( 0 ).set_mana( 666 );
#ifdef DEBUG
	cout << "A:" << action_ATTACK << flush;
  cout << "A#" << actor0.get_mana() << flush;
#endif

			break;

			default: break;
	 }
}
