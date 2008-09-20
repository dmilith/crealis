module unittests;

import std.stdio;

void main() {
    writefln("test");
    /* This assertion will fail. */
    assert(false);  

    /* 
        The line number (7) may be different, but this is the 
        error message which should appear...
        Error: AssertError Failure unittests(7)
    */
}

class Whatever {
   
    unittest {
        writefln("class Whatever UnitTest...");
        /* If the expession of an assert doesn't evaluate to true, an exception is thrown at run-time. */

        assert(true==1);
        assert(true);
        assert(false==false);
        assert(!false);
    }
}

unittest {
    writefln("module UnitTest...");
    assert(true==1);
    assert(true);
    assert(false==false);
}

