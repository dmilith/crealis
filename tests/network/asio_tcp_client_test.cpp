#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include "../../character.h"
#include "../../soul.h"
#include "../../network.h"

using boost::asio::ip::tcp;
Ccharacter *z = new Ccharacter();
Ccharacter *zz = new Ccharacter();


int main(int argc, char* argv[]) {
  try {
    
    boost::asio::io_service io_service;

    tcp::resolver resolver( io_service );
    std::string host = DEFAULT_HOST;

    if ( argc == 2 ) {
      host = argv[1];
    }

    tcp::resolver::query query( tcp::v4(), host, DEFAULT_PORT );
    tcp::resolver::iterator iterator = resolver.resolve( query );

    tcp::socket s( io_service );
    s.connect(*iterator);

    using namespace std; // For strlen.
    z->set_age( 666 );

    std::string zzzz = "yep that's me !";
    z->set_name( zzzz );
    for ( int i = 0; i < 10000; i++ ) {
    boost::asio::write( s, boost::asio::buffer( z, sizeof( Ccharacter ) ) );

    size_t reply_length = boost::asio::read( s, boost::asio::buffer( zz, sizeof( Ccharacter ) ) );
    std::cout << "Reply is: ";
    std::cout << zz->get_age() << " " << zz->get_name();
    std::cout << "\n";
    sleep( 1 );
    }
  }
  catch ( std::exception& e ) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

