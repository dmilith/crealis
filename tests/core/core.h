#ifndef _CCORE_H
#define _CCORE_H

#include <iostream>
#include <cassert>
#include <fstream>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "../../hashlib/hl_tools.h"
#include "../../coordinates.h"
#include "../../version.h"
#include "../../config.h"

#define MAX_OBJECTS_AMOUNT 100

using namespace std;


namespace core {

  class Ccore {
    
    private:
      uint32_t objects_amount;
      void save_objects_amount();
      void load_objects_amount();

    public:
      Ccore();
      ~Ccore();
      string get_core_version();
      void set_amount( uint32_t value_ );
      uint32_t get_current_objects_amount();
      uint32_t get_max_objects_amount();
  };


  class Cobject : public Ccore {

    private:
      string id;
      Ccoordinates position; // localization of object in world
      int8_t priority;

    public:
      Cobject();
      Cobject( int8_t priority_ );
      Cobject( string id_ );
      Cobject( string id_, int8_t priority_ ) ;
      string get_id();
      virtual bool is_changed();
      void set_id( string id_ );
      int8_t get_priority();
      void set_priority( int8_t priority_ );
      virtual bool save(); // saving with id as filename
      virtual Cobject load( string filename_ );

  };

}; // namespace

#endif
