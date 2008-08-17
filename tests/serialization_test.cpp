/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

//#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/base_object.hpp>
//#include <boost/serialization/vector.hpp>

class MyContainer {
    friend class boost::serialization::access;
    int32_t
			base_health,
		  health,
			intelligence,
			strength,
			dexterity,
			instinct, // instynkt im wyzszy tym postac bardziej potrafi wyczuc jakie ma szanse z przeciwnikiem :}
			mind_strength;//cechy postaci
      uint32_t age; // wiek postaci
      int32_t luck; //szczescie moze byc -
      int64_t gold;
      
//    public:   
    template<class Archive>
    void
    save( Archive & ar, const unsigned int version ) const {
       // ar & boost::serialization::base_object< >(*this);
        ar & base_health,
        ar & health,
        ar & intelligence,
        ar & strength,
        ar & dexterity,
        ar & instinct, // instynkt im wyzszy tym postac bardziej potrafi wyczuc jakie ma szanse z przeciwnikiem :}
        ar & mind_strength;//cechy postaci
        ar & age; // wiek postaci
        ar & luck; //szczescie moze byc -
        ar & gold;
    }
    
    template<class Archive>
    void
    load(Archive & ar, const unsigned int version)
    {
        ar & base_health,
        ar & health,
        ar & intelligence,
        ar & strength,
        ar & dexterity,
        ar & instinct, // instynkt im wyzszy tym postac bardziej potrafi wyczuc jakie ma szanse z przeciwnikiem :}
        ar & mind_strength;//cechy postaci
        ar & age; // wiek postaci
        ar & luck; //szczescie moze byc -
        ar & gold;
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()
 //     Ccoordinates pos; //pozycja postaci w swiecie
//	Cbackpack backpack( Esize ); //plecak
//	Csoul soul; // aktualna dusza :}
//	Eraces race;
 // std::vector<Citem*> items; // capacity 2 -> two hands 
};

//class bus_route : MyContainer {
//    friend class boost::serialization::access;
//    std::vector<MyContainer *> stops;
//    std::string driver_name;
//    template<class Archive>
//    void save(Archive & ar, const unsigned int version) const
//    {
//        // note, version is always the latest when saving
//        ar & boost::serialization::base_object< MyContainer* >(*this);
//        ar & driver_name;
//        ar & stops;
//    }
//    template<class Archive>
//    void load(Archive & ar, const unsigned int version)
//    {
//        if(version > 0)
//            ar & driver_name;
//        ar  & stops;
//    }
//    BOOST_SERIALIZATION_SPLIT_MEMBER()
//public:
//    bus_route(){}
//};
//
//BOOST_CLASS_VERSION(bus_route, 1)

//BOOST_CLASS_VERSION( MyContainer, 1 )

int main() {
    //const bus_route();
    const MyContainer t();
    
    
}