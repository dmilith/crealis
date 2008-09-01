/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CJOB_H_
#define _CJOB_H_

#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
// TODO #include "world.h"
// TODO #include "map.h" 
#include "character.h"
#include "coordinates.h"
#include "core.h"
#include "hashlib/hl_tools.h"

using namespace std;
using namespace core;
using namespace boost;

enum ETypeOfJob {
			action_IDLE = 0,
			action_WALK = 1,
			action_RUN = 2,
			action_ATTACK = 10
};


class Job : public Cobject {

  private:
    
    string job_id, job_crc;
    uint32_t job_flags; // specified flags for non-standard types of jobs -not yet implemented
    ETypeOfJob type;
    Csoul actor0;
    Csoul actor1;
    void set_crc(); // FIXME
    
  public:
      // adding two objects with related action
    void create_job( Cobject& object0_, Cobject& object1_, ETypeOfJob action_ );
    void set_action( ETypeOfJob type_ );
    Csoul& get_actor( uint8_t actor_num_ );
    Job();
    ~Job();
    void run();

};


#endif
