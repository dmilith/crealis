#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/filesystem/operations.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/progress.hpp>
#include <signal.h>

#include "world.h"
#include "config.h"
#include "job.h"
#include "character.h"
#include "version.h"

//removing from stack
//std::vector<Job>::iterator rm = job_list.end();
//job_list.erase( rm );
static std::vector<Job> job_list;
Cworld *umbra; // umbra
Cworld *crealis; // noob land
uint64_t timer;
Ccharacter *a_man, *an_elve, *a_dwarf, *a_cave_troll;



void recv_signal( int sig ) {
	 std::cout << std::endl << "Bye" << std::endl;
	 //cleaning up
#ifdef DEBUG
	std::cout << "debug: saving world." << std::endl;
	std::cout.flush();
#endif
	 umbra->save_world();
	 crealis->save_world();
	 delete umbra;
	 delete crealis;
	 exit( 0 );
}


// execution of job
void get_job_from_stack() {
	if ( job_list.empty() ) {
#ifdef DEBUG
	std::cout << ".";
		 std::cout.flush();
#endif
		 return;
		 //exit( 0 );
	}
	//running job
	if ( ( job_list.at( job_list.size() - 1 ) ).actors.size() >= 1 ) {
			job_list.at( job_list.size() - 1 ).run();
			job_list.pop_back();
	}
}

void add_job_to_stack( Job job ) { 
	job_list.push_back( job );
}


// perform one job
void _do( ETypeOfJob action_to_perform, Ccharacter *c1, Ccharacter *c2 = NULL ) {
	 		Job *action;
				action = new Job();
				action->job_info = "FFF";
				action->job_data = "data2";
				action->type = action_to_perform;
				if ( c1 == NULL ) {
#ifdef DEBUG
	std::cout << "\nCatched on trying perform a job without c1! ";
	std::cout.flush();
	exit( 1 );
#endif
					 return;
				}
				action->actors.push_back( c1 );
				if ( c2 != NULL ) {
					action->actors.push_back( c2 );
				}
				add_job_to_stack( *action );
	 delete action;
}

std::string& print_character( Ccharacter *ch ) {
	 std::cout << std::endl <<
			"Name:" << ch->name << ", " <<
			"Age:" << ch->age << ", " <<
			"Race:" << ch->race << ", " <<
			"Health:" << ch->health << ", " <<
			"Int:" << ch->intelligence << ", " <<
			"Dex:" << ch->dexterity << ", " <<
			"Str:" << ch->strength << ", " <<
			"Luck:" << ch->luck << ", " <<
			"M-Str:" << ch->mind_strength << ".";
	 std::cout.flush();
}

// main threads:
//
void thread_console() {
	 char command = '-';
#ifdef DEBUG
	std::cout << "Console Ready!" << std::endl;
	std::cout.flush();
#endif
		 do {
	 			std::string *command_str = new std::string();
				std::cout << std::endl << "#_:";
				std::cout.flush();
				*command_str = std::cin.get();
#ifdef DEBUG
#endif
				if ( *command_str == "s") command = '-';
				if ( *command_str == "i") command = 'i';
				if ( *command_str == "a" ) command = '1';
				if ( *command_str == "d" ) command = '2';
				if ( *command_str == "q" ) command = 'q';
				delete command_str;
				switch( command ) {
					case 'q':
						 recv_signal( 0 );
						 exit( 0 );
					case '-':
						 break;
					case 'i':
						 _do( action_IDLE, a_man );
						 std::cout << "Done IDLE: " << std::endl;
						 std::cout << print_character( a_man );
						 std::cout.flush();
						 break;
					case '1':
						 _do( action_ATTACK, a_man, a_cave_troll );
						 std::cout << "Done ATTACK: " << std::endl;
						 std::cout << print_character( a_man ) << print_character( a_cave_troll );
						 std::cout.flush();
						 break;
					case '2':
						 _do( action_ATTACK, a_cave_troll, a_man );
						 std::cout << "Done DEFEND: " << std::endl << print_character( a_cave_troll ) << print_character( a_man );
						 std::cout.flush();
						 break;
					 default:
							break;
				}
		 } while( true );
}


void thread_timer() {
	boost::xtime xt;
	 do {
#ifdef DEBUG
	//set bright red ANSI color in console
	printf("%c[%d;%d;%dm", 0x1B, BRIGHT, GREEN, BG_BLACK);
	std::cout << (uint64_t)timer; //loop_timer.elapsed(); //std::endl;
	std::cout.flush();
	//reset ANSI code to default:
	printf("%c[%dm", 0x1B, 0);
#endif
#ifndef DEBUG
		boost::xtime_get( &xt, boost::TIME_UTC );
#endif
#ifdef DEBUG
	std::time_t now;
	std::time ( &now );
	boost::xtime_get( &xt, boost::TIME_UTC );
	std::cout << "[" << now << "]$ " << std::endl;
	std::cout.flush();
	xt.nsec += 500000000; // adding additional slowdown
#endif
		xt.nsec += 500000000; // half second
		boost::thread::sleep( xt );
		++timer;
#ifdef DEBUG
	if ( timer % 241 == 0 ) {
		_do( action_ATTACK, a_cave_troll, a_man );
	}
#endif
	} while ( true );
}

void thread_main_loop() {
	boost::timer loop_timer;
	boost::xtime xt;
	 do {
#ifdef DEBUG
		//set bright red ANSI color in console
		printf("%c[%d;%d;%dm", 0x1B, BRIGHT,RED,BG_BLACK);
		std::cout << ".";
		std::cout.flush();
	  //reset ANSI code to default:
	  printf("%c[%dm", 0x1B, 0);
#endif		
	 boost::xtime_get( &xt, boost::TIME_UTC );
		xt.nsec += 5000;
#ifdef DEBUG
		xt.nsec += 200000000;	
#endif
		get_job_from_stack();
		boost::thread::sleep( xt );
	 } while ( true );

}


#ifdef DEBUG
#endif

/*
 * server
 */
int main( int argc, char* argv[] ) {
	signal( SIGINT, recv_signal );
	signal( SIGTERM, recv_signal );
	
	// creating worlds
	umbra = new Cworld( 255, 255, 255, 255, 0 );
	umbra->load_world();
	crealis = new Cworld( 1, 1, 3, 3, 1.2 );
	crealis->load_world();

	// creating objects/ players
	an_elve = new Ccharacter( (Eraces)elve );
	an_elve->name = "Gabriel";
	a_man = new Ccharacter( (Eraces)human );
	a_man->name = "Dmilith";
	a_dwarf = new Ccharacter( (Eraces)dwarf );
	a_dwarf->name = "Glorn";
	a_cave_troll = new Ccharacter( (Eraces)cave_troll );
	a_cave_troll->name = "Burgh";

	umbra->characters.push_back( a_man ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
	umbra->characters.push_back( an_elve ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
	umbra->characters.push_back( a_dwarf ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
	umbra->characters.push_back( a_cave_troll ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy

#ifdef DEBUG
	std::cout << std::endl << "@" << an_elve->name << "^" << an_elve->health <<"^" << an_elve->strength <<  ", ";
	std::cout << std::endl << "@" << a_man->name << "^" << a_man->health << "^" << a_man->strength << ", ";
	std::cout << std::endl << "@" << a_dwarf->name << "^" << a_dwarf->health <<"^" << a_dwarf->strength <<  ", ";
	std::cout << std::endl << "@" << a_cave_troll->name << "^" << a_cave_troll->health << "^" << a_cave_troll->strength <<  ", ";
	std::cout.flush();
#endif

	boost::thread timer_thread( &thread_timer );
	boost::thread main_loop_thread( &thread_main_loop );
	boost::thread console_thread( &thread_console );
	// wait for the thread to finish
	timer_thread.join();
	main_loop_thread.join();
	console_thread.join();
	recv_signal( 0 );
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
