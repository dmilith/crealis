/*
 
    This is OpenSource Project;
    It's licensed on GPL/ LGPL public license;
    It's written by Daniel (dmilith) Dettlaff since August 2oo8.
    You can redistribute this project only with this header.
    
*/

#ifndef _CCONFIG_H_
#define _CCONFIG_H_

#include <string>

#define DEBUG
//#define RUBY_EMB

const std::string SLASH = "/";
const std::string BACKSLASH = "\\";
static std::string pp = SLASH; // "normal" UNIX slash to separate parts path

// main declarations and constants
#ifndef WIN32
 #include <cstdlib>
 const std::string MAIN_DIR = std::string( getenv( "HOME" ) ) + pp + ".cWorld";
#else
 pp = BACKSLASH;
 // TODO: fix static path for windows 
 const std::string MAIN_DIR = std::string( "C:" + pp + "CWorld" );
#endif

const std::string WORLD_SAVE_PATH = "save" + pp;
const std::string JOB_SAVE_PATH = "jobs" + pp;


/*
ANSI Attributes
	0    All attributes off
	1    Bold on
	4    Underscore (on monochrome display adapter only)
	5    Blink on
	7    Reverse video on
	8    Concealed on

Foreground colors
	30    Black
	31    Red
	32    Green
	33    Yellow
	34    Blue
	35    Magenta
	36    Cyan
	37    White

Background colors
	40    Black
	41    Red
	42    Green
	43    Yellow
	44    Blue
	45    Magenta
	46    Cyan																																																																			        47    White
*/

// ANSI color codes
#define BG_BLACK 40
#define BRIGHT 1
#define RED 31
#define GREEN 32
#define MAGENTA 35

#endif
