#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include "../character.h"
#include "../soul.h"
#include "../network.h"

using boost::asio::ip::tcp;
Ccharacter *z = new Ccharacter();
Ccharacter *zz = new Ccharacter();


int main(int argc, char* argv[]) {
  try {
    
/*    if ( argc != 2 ) {
      std::cerr << "Usage: tcp_server <host>\n";
      return 1;
    }
*/

    boost::asio::io_service io_service;

    tcp::resolver resolver( io_service );
    tcp::resolver::query query( tcp::v4(), DEFAULT_HOST, DEFAULT_PORT );
    tcp::resolver::iterator iterator = resolver.resolve( query );

    tcp::socket s( io_service );
    s.connect(*iterator);

    using namespace std; // For strlen.
    z->set_age( 666 );
    z->set_name( "yep that's me" );
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

