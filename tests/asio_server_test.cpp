//
// blocking_udp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include "../character.h"
#include "../soul.h"

using boost::asio::ip::udp;

//enum { max_length = 1024 };
Ccharacter *z = new Ccharacter();


void server( boost::asio::io_service& io_service, short port ) {
  udp::socket sock( io_service, udp::endpoint( udp::v4(), port ));
  for ( ;; ) {
    //char data[ max_length ];
    udp::endpoint sender_endpoint;
    size_t length = sock.receive_from( boost::asio::buffer( z, sizeof( Ccharacter ) ), sender_endpoint );
    std::cout << "Connected: " << sender_endpoint << std::endl << std::flush;
    sock.send_to( boost::asio::buffer( z, sizeof( Ccharacter ) ), sender_endpoint );
    std::cout << "Sent reply to: " << sender_endpoint << std::endl << std::flush;
  }
}

int main( int argc, char* argv[] ) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: blocking_udp_echo_server <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;

    using namespace std; // For atoi.
    server( io_service, atoi( argv[1] ) );
  }
  catch ( std::exception& e ) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  delete z;
  return 0;
}

