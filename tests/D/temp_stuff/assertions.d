import std.stdio;

void main() {
    writefln("Let's test some assertions...");

    /* These assertions should succeed -- they evaluate to true. */

    assert(true);
    assert('\xAA' == '\u00AA');
    assert(221 % 5 == 1);
    assert(25 * 4 * 20 + 4 == 2004);

    /*  This assertion fails... 
        Error: AssertError Failure assert.d(line number) */

    assert(false);    
    writefln("No problem, man.");
}

