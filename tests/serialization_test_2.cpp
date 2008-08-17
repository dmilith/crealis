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
//#include "../coordinates.h"

#include "../soul.h"
#include "../item.h"
#include "../character.h"

namespace boost {
namespace serialization {
        template<class Archive>
        void serialize(Archive & ar, Citem & item, const unsigned int version) {
            ar & item.weight;
            ar & item.size_of_item;
        } // namespace serialization
        
        template<class Archive>
        void serialize(Archive & ar, Ccoordinates & pos, const unsigned int version) {
            ar & pos.position;
            ar & pos.parent_positions;
        } // namespace serialization
        
        template<class Archive>
        void serialize(Archive & ar, Csoul & soul, const unsigned int version) {
            ar & soul.mind_strength;
            ar & soul.mana;
            ar & soul.alignment;
            ar & soul.soul_exist; // czy istnieje dusza czy nie
        } // namespace serialization
        
        template<class Archive>
        void serialize(Archive & ar, Ccharacter & ch, const unsigned int version) {
            ar & ch.base_health;
            ar & ch.dead;
            ar & ch.health;
            ar & ch.intelligence;
            ar & ch.strength;
            ar & ch.dexterity;
            ar & ch.instinct; // instynkt im wyzszy tym postac bardziej potrafi wyczuc jakie ma szanse z przeciwnikiem :}
            ar & ch.mind_strength;//cechy postaci
            ar & ch.age; // wiek postaci
            ar & ch.luck; //szczescie moze byc -
            ar & ch.soul;
            ar & ch.gold;
            ar & ch.pos;
            ar & ch.items;
            ar & ch.private_box;
            ar & ch.race;
        } // namespace serialization
    } // namespace boost
}

int main() {
    // create and open a character archive for output
    std::ofstream ofs("test_character_serialized");

    // create class instance
    Ccharacter g;
    Ccoordinates pos;
    g.pos = pos;
    Citem item;
    Csoul soul;
    item.weight = 5;
    soul.mana = 666;
    g.age = 12;
    g.gold = 0;
    g.soul = soul;
    g.items[0] = item;
    item.weight = 7;
    g.private_box[0] = item;
  //  std::cout << g.items.size();

    // save data to archive
    {
        boost::archive::binary_oarchive oa( ofs, 1 );
        // write class instance to archive
        oa << g;
    	// archive and stream closed when destructors are called
    }
    
    // ... some time later restore the class instance to its orginal state
    Ccharacter newg;
    {
        // create and open an archive for input
        std::ifstream ifs("test_character_serialized");
        boost::archive::binary_iarchive ia( ifs, 1 );
        //boost::archive::text_iarchive ia( ofs );
        // read class state from archive
        ia >> newg;
        std::cout << "x: " << newg.soul.mana << std::endl;
        std::cout << "y: " << newg.gold << std::endl;
        std::cout << "z: " << newg.items[0].weight << std::endl;
        std::cout << "p: " << newg.private_box[0].weight << std::endl;
        for ( int i = 0; i < 6; ++i ) {
            std::cout << i << ": " << pos.parent_positions[ i ] << std::endl;    
        }
        
       // newg.items.begin();
        // archive and stream closed when destructors are called
    }
    return 0;
}
