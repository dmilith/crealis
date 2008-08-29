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
static uint64_t characters_online; // current amount of online players
static uint64_t worlds_online;

static Cworld* worlds[ MAX_WORLDS ]; // world.h
static Ccharacter* characters[ MAX_PLAYERS ]; // world.h

void
init_structures() {
	for ( uint32_t i = 0; i < MAX_WORLDS; i++ ) worlds[ i ] = NULL;
	for ( uint32_t i = 0; i < MAX_PLAYERS; i++ ) characters[ i ] = NULL;
}

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
	save_world( *worlds[ 0 ], WORLD_SAVE_PATH + "umbra.world" );
	save_world( *worlds[ 1 ], WORLD_SAVE_PATH + "crealis.world" );
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
			job_list.at( job_list.size() - 1 ).run();
#ifdef DEBUG
			save_job( (Job)job_list.at( job_list.size() - 1), JOB_SAVE_PATH +
								(std::string)( job_list[ job_list.size() - 1 ] ).job_id + ".job" );
#endif								
			job_list.pop_back();
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
				action.actors[ 0 ] = c1;
				if ( c2 != NULL ) {
					action.actors[ 1 ] = c2;
				}
				add_job_to_stack( action );
}

const std::string&
print_character( Ccharacter* ch ) {
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
			  std::cin.getline( command_s, 128 );
	 			std::string command_str( command_s );
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
					case '0':
						 break;
					case 'i':
					 	 for ( int i = 0; i < 50000; i++ ) {
						 		_do( action_IDLE, characters[ 0 ] );
#pragma omp flush( worlds, characters, job_list, timer, characters_online, worlds_online )
						}
						 std::cout << "Done IDLE: " << std::endl;
						 std::cout << print_character( characters[ 0 ] );
						 std::cout.flush();
						 break;
					case '1':
#ifndef DEBUG
	std::cout << std::endl << std::time( 0 );
#endif
						//characters[ 1 ]->health = 400000000000;
				//	 	for ( int i = 0; i < 20000; i++ ) {
					 	 for ( int i = 0; i < 20000; i++ ) {
						 _do( action_ATTACK, characters[ 0 ], characters[ 1 ] );//, characters[ 1 ] );
#pragma omp flush( worlds, characters, job_list, timer, characters_online, worlds_online )
						}
				//		}
#ifndef DEBUG
	std::cout << std::endl << std::time( 0 );
#endif
						// _do( action_ATTACK, characters[ 0 ], characters[ 1 ] );
						 std::cout << "Done ATTACK: " << std::endl;
						 std::cout << print_character( characters[ 0 ] ) << print_character( characters[ 1 ] );
						 std::cout.flush();
						 break;
					case '2':
						 _do( action_ATTACK, characters[ 1 ], characters[ 0 ] );
						 std::cout << "Done DEFEND: " << std::endl;
						 std::cout << print_character( characters[ 1 ] ) << print_character( characters[ 0 ] );
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
	std::cout << "[" << now << "];" << std::endl;
	std::cout.flush();
	xt.nsec += 500000000; // adding additional slowdown
#endif
			xt.nsec += 500000000; // half second
			boost::thread::sleep( xt );
			++timer;
#ifdef DEBUG
	if ( timer % 10 == 0 ) {
		_do( action_ATTACK, characters[ 1 ], characters[ 0 ] );
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
		xt.nsec += 50;
#ifdef DEBUG
	xt.nsec += 200000000;	
#endif
		get_job_from_stack();
		boost::thread::sleep( xt );
	 } while ( true );
}


/*
void
setup_dirs() {
  // this method will check existance of main program directories and it will try to create them if they doesn't exist
  if ( !exists( MAIN_DIR ) ) create_directory( DSIP_MAIN_DIR );
}
*/

/*
 * server
 */
int
main( int argc, char* argv[] ) {

	signal( SIGINT, recv_signal );
	signal( SIGTERM, recv_signal );
	
	//init_structures(); // NULLify all dynamic structures

	// creating worlds
	// TODO: make it on vector
	worlds[ 0 ] = new Cworld( "Umbra", 255, 255, 0 );
	worlds[ 1 ] = new Cworld( "Crealis", 20, 80, 50 );
	worlds_online = 2;

	if ( boost::filesystem::exists( WORLD_SAVE_PATH ) ) {
		load_world( *worlds[0], WORLD_SAVE_PATH + "umbra.world" );
		load_world( *worlds[1], WORLD_SAVE_PATH + "crealis.world" );
	}

	characters[ 0 ] = new Ccharacter( human, "Marys" ); 
	characters[ 1 ] = new Ccharacter( elve, "Gabriel" );
	characters[ 2 ] = new Ccharacter( dwarf, "Mirmil" );
	characters[ 3 ] = new Ccharacter( cave_troll, "Burgh" );
	characters_online = 4;


#ifdef _OPENMP
	std::cout << "OpemMP version " << _OPENMP << " initialized." << std::endl;
	std::cout << "Running on machine with " << omp_get_num_procs() << " core(s)." << std::endl;
	std::cout.flush();


#pragma omp parallel sections \
						shared( worlds, characters, job_list, timer, characters_online, worlds_online ) \
						num_threads ( 3 )
	 {
			 #pragma omp section
			 {
		 		 thread_main_loop();
			 }
			 #pragma omp section
			 {
				 thread_timer();
			 }
			 #pragma omp section
			 {
			 	 thread_console();
			 }
	 }

{
	std::cout<<"Created "<< omp_get_num_threads() <<" Threads"<<std::endl;
// enable dynamic Threads
	 if ( omp_get_dynamic() ) omp_set_dynamic( 1 );

//#ifdef DEBUG
int64_t i;
	#pragma omp for schedule( static, 2 )
		for ( i = 0; i < 20000; i++ )
		{
			int z = 1;
			if (! i % 2 ) z = 2;
				else if (! i % 3 ) z = 3;
					else z = 1;
						
			switch( z ) {
					case 1:
						std::cout << "1";
						std::cout.flush();
						_do( action_IDLE, characters[ 0 ] );
						break;
					case 2:
						std::cout << "2";
						std::cout.flush();
						_do( action_IDLE, characters[ 0 ] );
						break;
					case 3:
						std::cout << "3";
						std::cout.flush();
						_do( action_IDLE, characters[ 0 ] );
						break;
			}
		}
///#endif

	 #pragma omp barrier
	 { // all threads must execute this one
			std::cout << "BAR" << std::endl;
			std::cout.flush();
	 }
   
/*	 #pragma omp critical
	 { // executed only by One Thread.
	 	 // good place for Network related operations
			std::cout << "CRI" << std::endl;
			std::cout.flush();
   }
 */
}
#else
 std::cout << "Your compiler does not support OpenMP!" << std::endl;
 recv_signal( 0 );
#endif

/*
	boost::thread timer_thread( &thread_timer );
	boost::thread main_loop_thread( &thread_main_loop );
	boost::thread console_thread( &thread_console );

	// wait for the threads to finish
	timer_thread.join();
	main_loop_thread.join();
	console_thread.join();
*/	
	recv_signal( 0 );
	return 0;
}

