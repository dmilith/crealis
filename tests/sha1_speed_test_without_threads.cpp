#include "../hashlib/hl_tools.h"
#include <iostream>

using namespace std;

int main() {
    time_t timer_time = time( NULL );
    clock_t timer = clock();
	
    for ( int i = 0; i < 2000000; i++ ) {  	
    		generate_sha1();
  	}

    clock_t elapsed = ( clock() - timer ) / CLOCKS_PER_SEC;
    time_t elapsed_time = time( NULL ) - timer_time;
    cout << elapsed_time << "seconds" << endl << flush;
    cout << elapsed << "ticks (s)" << endl << flush;
  	
  	return 0;
}
