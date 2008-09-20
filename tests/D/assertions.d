//import std.stdio;
//import core;

//extern class Ccore;

void main() {

    writefln("Let's test some assertions...");

    /* These assertions should succeed -- they evaluate to true. */
    assert(true);
    assert('\xAA' == '\u00AA');
    assert(221 % 5 == 1);
    assert(25 * 4 * 20 + 4 == 2004);

    writefln("No problem, man.");
    
    Ccore core = new Ccore();
    writefln( core.get_core_version );

}

