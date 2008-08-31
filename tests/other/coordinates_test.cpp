#include "../../coordinates.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main() {

  Ccoordinates position;

  cout << position.position << endl;
  assert ( sizeof( position.position ) == 41 );

  for ( int i = 0; i < 6; i++ ) {
    for ( int j = 0; j < 40; j++ ) {
      cout << position.parent_positions[i][j];
    }  
    cout << endl;
  }


  return 0;
}
