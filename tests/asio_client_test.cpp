//
// blocking_udp_echo_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "../character.h"
#include "../soul.h"


using boost::asio::ip::udp;

//enum { max_length = 1024 };
Ccharacter *z = new Ccharacter();
Ccharacter *zz = new Ccharacter();

void handler(const boost::system::error_code& error)
{
  if (!error)
  {
    // Timer expired.
    std::cout << "WOOF" << std::flush;
    //exit( 0 );
  }
}


int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {
      std::cerr << "Usage: blocking_udp_echo_client <host> <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;
// Construct a timer without setting an expiry time.
boost::asio::deadline_timer timer(io_service);

// Set an expiry time relative to now.expires_from_now(seconds(5)
timer.expires_from_now(boost::posix_time::seconds(3));

    udp::socket s( io_service, udp::endpoint( udp::v4(), 0 ) );

    udp::resolver resolver( io_service );
    udp::resolver::query query( udp::v4(), argv[1], argv[2] );
    udp::resolver::iterator iterator = resolver.resolve( query );
    
    using namespace std; // For strlen.
    z->set_age( 666 );
    z->set_name( "yep that's me" );
    s.send_to( boost::asio::buffer( z, sizeof( Ccharacter ) ), *iterator );

    timer.async_wait(handler);
    io_service.run();
    
    udp::endpoint sender_endpoint;
    size_t reply_length = s.receive_from( boost::asio::buffer( zz, sizeof( Ccharacter ) ), sender_endpoint );
    std::cout << "Reply is: ";
    std::cout << zz->get_age() << " " << zz->get_name();
    std::cout << "\n";
  }
  catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

