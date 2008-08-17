#ifndef _CCOORDINATES_H_
#define _CCOORDINATES_H_

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/version.hpp>

std::string
generate_sha1( bool timeize_srand = false );

class Ccoordinates {
public:
	Ccoordinates(); //zerowanie koordynatow -zeby nie bylo zadnych krzakow
	std::string position; // sha1 identyfikujące daną pozycję mapy
	std::string parent_positions[6]; // sha1 z sha sąsiadujących elementów liczone od lewego boku 6 kąta
};

#endif //_CCOORDINATES_H_
