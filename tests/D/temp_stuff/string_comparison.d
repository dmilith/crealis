import std.stdio;

int main() {
  char[] str1 = "Aardvark";
  char[] str2 = "Zebra";
  char[] str3 = "1";


  /* "less than" operator */
  if ( str1 < str2 ) 
    writefln("Aardvark comes before Zebra.");
  else
    writefln("Aardvark comes after Zebra.");


  /* "greater" than operator */
  if ( str1 > str2 ) 
    writefln("Aardvark comes after Zebra.");
  else
    writefln("Aardvark comes before Zebra.");


  /* "equality" operator */
  if ( str1 == str2 ) 
    writefln("Aardvark is Zebra?!");
  else
    writefln("Aardvark is NOT Zebra.");


  /* "concatenation" operator */
  for (int i = 0; i < 3; i++) 
    str3 ~= "0";
  writefln(str3);

  return 0;
}

