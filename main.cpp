#include <iostream>
#include <boost/filesystem/operations.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/progress.hpp>

#include <signal.h>

#include "world.h"
#include "config.h"


void thread_timer() {
	boost::timer loop_timer;
	boost::xtime xt;
	std::cout << "Endless Timer Thread" << std::endl;
	//std::cout << loop_timer.elapsed();
	 do {
#ifdef DEBUG
		//set bright red ANSI color in console
		printf("%c[%d;%d;%dm", 0x1B, BRIGHT, GREEN, BG_BLACK);
		std::cout << loop_timer.elapsed(); //std::endl;
		fflush( stdout );
	  //reset ANSI code to default:
	  printf("%c[%dm", 0x1B, 0);
#endif		
		boost::xtime_get( &xt, boost::TIME_UTC );
		xt.nsec += 100000000;
		boost::thread::sleep( xt ); 
	 } while ( true );
}

void thread_main_loop() {
	boost::timer loop_timer;
	boost::xtime xt;
	std::cout << "Endless Main Loop Thread" << std::endl;
	 do {
#ifdef DEBUG
		//set bright red ANSI color in console
		printf("%c[%d;%d;%dm", 0x1B, BRIGHT,RED,BG_BLACK);
		std::cout << ".";
		fflush( stdout );
	  //reset ANSI code to default:
	  printf("%c[%dm", 0x1B, 0);
#endif		
	 boost::xtime_get( &xt, boost::TIME_UTC );
		xt.nsec += 100000000;
		boost::thread::sleep( xt ); 
	 } while ( true );

}

void recv_signal( int sig ) {
	exit( 0 );
}


/*
 * server
 */
int main( int argc, char* argv[] ) {
	signal( SIGINT, recv_signal );
	signal( SIGTERM, recv_signal );
	
	boost::thread timer_thread( &thread_timer );
	// wait for the thread to finish
	#ifdef DEBUG
	    std::cout << "debug: Timer thread joined." << std::endl;
	#endif
	#ifdef DEBUG
			std::cout << "debug: Main loop thread joined." << std::endl;
			fflush( stdout );
	#endif
	
	boost::thread main_loop_thread( &thread_main_loop );
	
	// wait for the threads to finish
	main_loop_thread.join();
	timer_thread.join();

	return 0;
}

	 /*Cworld delmirum; //swiat delmirum (mroczne krolestwo), 
			    //przykladowo 10 na 10 theritoriow ;} na 200 graczy styka lekko;}
	Cworld crealis(1,1,3,3,1.2); //swiat crealis (dolina gluchej ciszy -noob'landia)
	//Cworld umbra(255,255,255,255,0); //ogrom, plus zero grawitacji.. czyli nie miejsce dla smiertelnikow :}
	
	//std::vector<Cworld> delmirum;
	
	crealis.name="crealis";
	crealis.theritory.name="neomis";
	crealis.theritory.place.name="cathalith village";
	crealis.theritory.place.map.name="alley of the cathalith";
	
	//modyfikujemy pozycje w crealis
	
	delmirum.character.push_back( Ccharacter() ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
	
		//tworzymy postac krasnoluda
		crealis.character.push_back( Ccharacter() );
		crealis.character[0].race=dwarf;
		crealis.character[0].strength=17;
		crealis.character[0].dexterity=7;
		crealis.character[0].luck=-5;
		crealis.character[0].intelligence=9;
		crealis.character[0].instinct=11; //instynkt postaci
		
		crealis.character.push_back( Ccharacter() );
	
	
	delmirum.name="delmirum";
	std::cout << "\nname:("<< crealis.name << ") char:("<<crealis.character[0].pos.mCoord 
			  << ") theirtory name: ("<< crealis.theritory.name << ")";
	std::cout <<"\ncrealis version:(" << crealis.version << ") creatures online (" 
			  << crealis.character.size() << ")\n";

	std::cout << "\nplaces: x:("<< crealis.xPlaceSize << ") y:("<< crealis.yPlaceSize 
			  << ") g:(" << crealis.gravity << ")";
	std::cout << "\ntheritories: x:("<< crealis.xTheritorySize << ") y:("<< crealis.yTheritorySize << ")";
	
	std::cout << "\nname:("<< delmirum.name << ") char:("<<delmirum.character[0].pos.mCoord 
			  << ") theritory name: ("<< delmirum.theritory.name << ")";

	std::cout << "\nplaces: x:("<< delmirum.xPlaceSize << ") y:("<< delmirum.yPlaceSize 
			  << ") g:(" << delmirum.gravity << ")";
	std::cout << "\ntheritories: x:("<< delmirum.xTheritorySize << ") y:("<< delmirum.yTheritorySize << ")\n";
	
	std::cout << "\n\n crealis character [0] territory  x(" 
			  << crealis.character[0].pos.tCoord.x << ") y:("<<crealis.character[0].pos.tCoord.y<<")\n" ;
	
	char z;
	std::cin >> z ;	
	*/
