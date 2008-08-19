/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#include "main.h"

//removing from stack
//std::vector<Job>::iterator rm = job_list.end();
//job_list.erase( rm );

static std::vector<Job> job_list;
static uint64_t timer;
Ccharacter a_man( human, "zdzich" ), an_elve( elve, "rodżer"), a_dwarf( dwarf, "glon"), a_cave_troll( cave_troll, "brugh" );
static Cworld worlds[ MAX_WORLDS ]; // world.h
static Ccharacter characters[ MAX_PLAYERS ]; // world.h

// save data to archive
void
save_job( Job job, std::string filename ) {
    std::ofstream ofs( filename.c_str() );
	  boost::archive::binary_oarchive oa( ofs, 1 ); // 1 means without header
    // write class instance to archive
    oa << job;
  	// archive and stream closed when destructors are called
}

// load data from archive
void
load_job( Job job, std::string filename ) {
	// create and open an archive for input
	std::ifstream ifs( filename.c_str() );
	boost::archive::binary_iarchive ia( ifs, 1 );
	// read class state from archive
	ia >> job;
}

// save data to archive
void
save_world( Cworld world, std::string filename ) {
    std::ofstream ofs( filename.c_str() );
	  boost::archive::binary_oarchive oa( ofs, 1 ); // 1 means without header
    // write class instance to archive
    oa << world;
  	// archive and stream closed when destructors are called
}

// load data from archive
void
load_world( Cworld world, std::string filename ) {
        // create and open an archive for input
        std::ifstream ifs( filename.c_str() );
        boost::archive::binary_iarchive ia( ifs, 1 );
        // read class state from archive
        ia >> world;
}


void
recv_signal( int sig ) {
	std::cout << std::endl << "Bye" << std::endl;
#ifdef DEBUG
	std::cout << "debug: saving world." << std::endl;
	std::cout.flush();
#endif
	save_world( worlds[ 0 ], WORLD_SAVE_PATH + "umbra.world" );
	save_world( worlds[ 1 ], WORLD_SAVE_PATH + "crealis.world" );
	exit( 0 );
}


// execution of job
void
get_job_from_stack() {
	if ( job_list.empty() ) {
#ifdef DEBUG
	printf("%c[%d;%d;%dm", 0x1B, BRIGHT, MAGENTA, BG_BLACK);
	std::cout << ".";
	printf("%c[%dm", 0x1B, 0);
	std::cout.flush();
#endif
		 return;
	}
	//running job
//	if ( ( job_list.at( job_list.size() - 1 ) ).actors.size() >= 1 ) {
			job_list.at( job_list.size() - 1 ).run();
			save_job( (Job)job_list.at( job_list.size() - 1), JOB_SAVE_PATH +
								(std::string)( job_list[ job_list.size() - 1 ] ).job_id + ".job" );
			job_list.pop_back();
//	}
}


void
add_job_to_stack( Job job ) { 
	job_list.push_back( job );
}


// perform one job
void
_do( ETypeOfJob action_to_perform, Ccharacter *c1, Ccharacter *c2 = NULL ) {
	 		Job action;
			action.job_flags = 0;
			action.job_id = generate_sha1( true ); // should be identifier. maybe sha1?
			action.type = action_to_perform;
				if ( c1 == NULL ) {
#ifdef DEBUG
	std::cout << "\nCatched on trying perform a job without c1! ";
	std::cout.flush();
	exit( 1 );
#endif
					 return;
				}
				action.actors[ 0 ] = *c1;
				if ( c2 != NULL ) {
					action.actors[ 1 ] = *c2;
				}
				add_job_to_stack( action );

			//delete action;
}

std::string& print_character( Ccharacter& ch ) {
	 std::cout << std::endl <<
			"Name:" << ch.name << ", " <<
			"Age:" << ch.age << ", " <<
			"Race:" << ch.race << ", " <<
			"Health:" << ch.health << ", " <<
			"Int:" << ch.intelligence << ", " <<
			"Dex:" << ch.dexterity << ", " <<
			"Str:" << ch.strength << ", " <<
			"Luck:" << ch.luck << ", " <<
			"M-Str:" << ch.mind_strength << ".";
	 std::cout.flush();
}


// main threads:
//
void
thread_console() {
#ifdef RUBY_EMB	
	ruby_init();
	ruby_init_loadpath();
#endif
	 char command = '-';
	 char command_s[128]; // = new std::string();
#ifdef DEBUG
	std::cout << "Console Ready!" << std::endl;
	std::cout.flush();
#endif
		 do {
				std::cout << std::endl << "#(con)_:";
				std::cout.flush();
			  std::cin.getline( command_s, 60 );
	 			std::string command_str( command_s );
#ifdef DEBUG
#endif
				command = '0';
				if ( command_str == "s") command = '0';
				if ( command_str == "i") command = 'i';
				if ( command_str == "a" ) command = '1';
				if ( command_str == "d" ) command = '2';
				if ( ( command_str == "q" ) || ( command_str == "quit" ) || ( command_str == "exit" ) ) command = 'q';
				switch( command ) {
					case 'q':
#ifdef RUBY_EMB
	ruby_finalize();
#endif
						 recv_signal( 0 );
						 exit( 0 );
					case '0':
						 break;
					case 'i':
						 _do( action_IDLE, &a_man );
						 std::cout << "Done IDLE: " << std::endl;
						 std::cout << print_character( a_man );
						 std::cout.flush();
						 break;
					case '1':
						 _do( action_ATTACK, &a_man, &a_cave_troll );
						 std::cout << "Done ATTACK: " << std::endl;
						 std::cout << print_character( a_man ) << print_character( a_cave_troll );
						 std::cout.flush();
						 break;
					case '2':
						 _do( action_ATTACK, &a_cave_troll, &a_man );
						 std::cout << "Done DEFEND: " << std::endl;
						 std::cout << print_character( a_cave_troll ) << print_character( a_man );
						 std::cout.flush();
						 break;
					 default:
							break;
				}
		 } while( true );
}


void
thread_timer() {
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
	if ( timer % 100 == 0 ) {
		_do( action_ATTACK, &a_cave_troll, &a_man );
	}
#endif
#ifdef DEBUG
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
	//reset ANSI code to default:
	printf("%c[%dm", 0x1B, 0);
	std::cout.flush();
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

  
/*
 * server
 */
int main( int argc, char* argv[] ) {
	signal( SIGINT, recv_signal );
	signal( SIGTERM, recv_signal );

	// creating worlds
	Cworld umbra( "Umbra", 255, 255, 0 );
	Cworld crealis( "Crealis", 20, 80, 50 );
	
	//load_world( umbra, "umbra.world");
	//load_world( crealis, "crealis.world");
	//adding new worlds to worlds vector
	worlds[ 0 ] = umbra;
	worlds[ 1 ] = crealis;
	
	// creating objects/ players
	
//	an_elve->name = "Gabriel";
//	a_man = new Ccharacter( (Eraces)human );
//	a_man->name = "Dmilith";
//	a_dwarf = new Ccharacter( (Eraces)dwarf );
//	a_dwarf->name = "Glorn";
//	a_cave_troll = new Ccharacter( (Eraces)cave_troll );
//	a_cave_troll->name = "Burgh";	

	Ccharacter a_man( human ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
	Ccharacter an_elve( elve );
	characters[ 0 ] = a_man;
	characters[ 1 ] = an_elve;

//	characters.push_back( *an_elve ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
//	characters.push_back( *a_dwarf ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
//	characters.push_back( *a_cave_troll ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy

#ifdef DEBUG
	std::cout << std::endl << "@" << an_elve.name << "^" << an_elve.health <<"^" << an_elve.strength <<  ", ";
	std::cout << std::endl << "@" << a_man.name << "^" << a_man.health << "^" << a_man.strength << ", ";
	std::cout << std::endl << "@" << a_dwarf.name << "^" << a_dwarf.health <<"^" << a_dwarf.strength <<  ", ";
	std::cout << std::endl << "@" << a_cave_troll.name << "^" << a_cave_troll.health << "^" << a_cave_troll.strength <<  ", " << std::endl;
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
