#include "../hashlib/hl_tools.h"
#include <boost/thread/thread.hpp>

void
thread_first() {
  for ( int i = 0; i < 500000; i++ ) {
    generate_sha1();
  }
}

void
thread_second() {
  for ( int i = 0; i < 500000; i++ ) {
    generate_sha1();
  }
}

int main() {
  boost::thread first_thread( &thread_first );
  boost::thread second_thread( &thread_second );
  first_thread.join();
  second_thread.join();
  return 0;
}
