#ifndef _CCORE_H
#define _CCORE_H

#include <iostream>
#include <cassert>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>

#include "../../hashlib/hl_tools.h"
#include "../../coordinates.h"
#include "../../version.h"

using namespace std;

namespace core {

  class Ccore {
    
    private:
      string id;

    public:
      Ccore();
      string get_core_version();
      string get_id();
      void set_id( string id_ );
      virtual bool is_changed();
      uint32_t get_objects_amount();
      
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
      int8_t get_priority();
      void set_priority( int8_t priority_ );
      virtual bool save(); // saving with id as filename
      virtual bool load( string filename_ );

  };

}; // namespace

#endif
