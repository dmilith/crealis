/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include <fstream>
// include headers that implement a archive in simple text format
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/version.hpp>
//#include <boost/serialization/split_member.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/version.hpp>
//#include "../coordinates.h"

#include "../soul.h"
#include "../item.h"
#include "../character.h"
#include "../world.h"
//
//#include "../serialized.h"


int main() {
    // create and open a character archive for output
    std::ofstream ofs("test_character_serialized");

    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout << generate_sha1() << std::endl;
    std::cout.flush();
    
    // create class instance
    Ccharacter g;
    Ccoordinates position;
    g.set_position( position );
    Citem item;
    Csoul* soul = new Csoul();
    item.weight = 5;
    soul->mana = 666;
    g.set_age( 12 );
    g.gain_gold( 10000 );
    g.set_soul( soul );
    //g.items[0] = &item;
    item.weight = 7;
    //g.private_box[0] = &item;
  //  std::cout << g.items.size();

    // save data to archive
    {
   //     boost::archive::binary_oarchive oa( ofs, 1 );
        // write class instance to archive
    //    oa << g;
    	// archive and stream closed when destructors are called
    }
    
    // ... some time later restore the class instance to its orginal state
 //   Ccharacter newg;
    {
        // create and open an archive for input
      //  std::ifstream ifs("test_character_serialized");
       // boost::archive::binary_iarchive ia( ifs, 1 );
        //boost::archive::text_iarchive ia( ofs );
        // read class state from archive
      //  ia >> newg;
        std::cout << "x: " << g.get_soul()->mana << std::endl;
        std::cout << "y: " << g.get_gold() << std::endl;
        //std::cout << "z: " << newg.items[0]->weight << std::endl;
        //std::cout << "p: " << newg.private_box[0]->weight << std::endl;
        for ( int i = 0; i < 6; ++i ) {
            std::cout << i << ": " << position.parent_positions[ i ] << std::endl;    
        }
        
       // newg.items.begin();
        // archive and stream closed when destructors are called
    }
    delete soul;
    return 0;
}
