/* Tested with DMD 0.118 */
/* Tested with DMD 1.0 */

import std.stdio;

int main (char[][] args)
{
    writef("Testing the D Code\n");
    writef("File:                %s\n",__FILE__);
    writef("Line:                %s\n",__LINE__);
    writef("Date:                %s\n",__DATE__);
    writef("Time:                %s\n",__TIME__);
    writef("TimeStamp:   %s\n",__TIMESTAMP__);
    writef("Version:     %s\n",__VERSION__);
    return 0;
}

