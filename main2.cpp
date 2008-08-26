#include <iostream>
//networking
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "main.h"

using namespace std;


void
save_world( Cworld world, std::string filename ) {
    std::ofstream ofs( filename.c_str() );
	  boost::archive::binary_oarchive oa( ofs, 1 ); // 1 means without header
    // write class instance to archive
    oa << world;
  	// archive and stream closed when destructors are called
}

// load data from archive
void
load_world( Cworld world, std::string filename ) {
	 // create and open an archive for input
	 std::ifstream ifs( filename.c_str() );
	 boost::archive::binary_iarchive ia( ifs, 1 );
	 // read class state from archive
	 ia >> world;
}


int
main() {
	Ccharacter* characters = new Ccharacter[ 100 ];
	characters[ 0 ].health = 0;
	uint64_t timer = 0;

  boost::asio::io_service io;


				for ( int i = 0; i < 50000; i++ ) {
					//set bright red ANSI color in console
					 printf("%c[%d;%d;%dm", 0x1B, BRIGHT, RED, BG_BLACK);
					 cout << "(A#):" << characters[ 0 ].health << "-";
					 characters[ 0 ].health += 1;
					 cout << characters[ 0 ].health;
				 	//reset ANSI code to default:
				 	 printf("%c[%dm", 0x1B, 0);
					 cout << flush;
        }
				for ( int i = 0; i < 50000; i++ ) {
					 printf("%c[%d;%d;%dm", 0x1B, BRIGHT, GREEN, BG_BLACK);
					 cout << "(B#):" << characters[ 0 ].health<< "-";;
					 characters[ 0 ].health += 1;
					 cout << characters[ 0 ].health;
				 	 printf("%c[%dm", 0x1B, 0);
					 cout << flush;
				}
				for ( int i = 0; i < 50000; i++ ) {
					 cout << "(C#):" << characters[ 0 ].health<< "-";;
					 characters[ 0 ].health += 1;
					 cout << characters[ 0 ].health << flush;
				}

	delete[] characters;
	return 0;
}

