#ifndef _CCORE_H
#define _CCORE_H

#include <iostream>
#include <cassert>

#include "../../hashlib/hl_tools.h"

namespace core {

class Ccore {
  
  private:
    std::string id;

  public:
    Ccore();
    std::string get_core_version();
    virtual std::string get_id();
    virtual void set_id( std::string id_ );
    bool is_changed();
    
};


class Cobject : public Ccore {

  private:
    std::string id;

  public:

    Cobject();
    ~Cobject();

};

}; // namespace

#endif
