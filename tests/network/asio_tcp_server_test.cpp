#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "../../character.h"
#include "../../soul.h"
#include "../../network.h"

#define VERBOSE

using boost::asio::ip::tcp;

Ccharacter *z = new Ccharacter();

//typedef boost::shared_ptr<Ccharacter> Character;
typedef boost::shared_ptr<tcp::socket> socket_ptr;

void session( socket_ptr sock ) {
  try {
#ifdef VERBOSE  
    std::cout << "New client " << sock->remote_endpoint() << " connected." << std::endl << std::flush;
#endif
    for (;;) {
      boost::system::error_code error;
      size_t length = sock->read_some( boost::asio::buffer( z, sizeof( Ccharacter ) ), error );
      if ( error == boost::asio::error::eof ) {
#ifdef VERBOSE
        std::cout << "Client " << sock->remote_endpoint() << " disconnected." << std::endl << std::flush;
#endif
        break; // Connection closed cleanly by peer.
      }
      else if ( error )
        throw boost::system::system_error( error ); // Some other error.
      boost::asio::write( *sock, boost::asio::buffer( z, sizeof( Ccharacter ) ));
    }
  }
  catch (std::exception& e) {
    std::cerr << "Exception in thread: " << e.what() << "\n";
  }
}

void server( boost::asio::io_service& io_service, short port ) {
  tcp::endpoint endpoint( tcp::v4(), port );
  tcp::acceptor a( io_service, endpoint );
#ifdef VERBOSE
  std::cout << "Listening at :" << endpoint << std::endl;
#endif
  for (;;) {
    socket_ptr sock( new tcp::socket( io_service ) );
    a.accept( *sock );
    boost::thread t( boost::bind( session, sock ));
  }
}

int main( int argc, char* argv[] ) {
  try {
    boost::asio::io_service io_service;
    using namespace std;
    server( io_service, atoi( DEFAULT_PORT ) );
  }
  catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

