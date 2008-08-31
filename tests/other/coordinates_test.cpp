#include "../../coordinates.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main() {

  Ccoordinates position;
  cout << position.get_position() << endl << strlen( position.get_position() ) << endl;
  assert( strlen( position.get_position() ) == 40 );
  cout << position.get_parent_position( 5 ) << endl;
  for ( int i = 0; i < 6; i++ ) {
    assert( strlen( position.get_parent_position( i ) ) == 40 );
  }
  cout << position.get_parent_position( 6 ) << endl;
  cout << position.get_position();

  return 0;
}

