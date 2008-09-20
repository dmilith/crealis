/*
 * Encoding:
 * Each word in a text is checked whether it is found in a 256 entry
 * dictionary08 (8 bits) or 512 entry dictionary16 (16 bits). A bit array
 * called "eightCode" is used to indicate which dictionary contained
 * the word. Associative arrays are used for the dictionaries.
 * "codes08" is an array of bytes with the sequence of 'hits' from
 * dictionary08. "codes16" is an array of ushorts with the sequence of
 * 'hits' from dictionary16.
 *
 * Decoding:
 * The "eightCode" bit array is traversed. If true, the corresponding word
 * is pulled from lookup08. If false, the corresponding word is pulled from
 * lookup16. The original "text" is compared with "check" for validation.
 *
 * Caveats:
 * - written by relatively inexperienced D programmer
 * - accomplishes so-so compression with fast decompression
 * 
 * Visual Studio 98 ide project files, exe, and full source available from:
 * http://bibledb.sourceforge.net/misc/ModuleTutorial.zip
 */

import Lookup;

import std.stdio;
import std.string;


const char[][] check  = ["", "", "", "", "", "", "", "", "", ""];

const char[][] text   = ["In", "the", "beginning", "God", "created", 
                         "the", "heavens", "and", "the", "earth."];


ubyte[10]  codes08;
ushort[10] codes16;
bit[10]    eightCode;

void main()
{
  Encode();
  Decode();
}

void Encode()
{
  int  i8 = 0;
  int  i16 = 0;

  foreach (int i, char[] word; text) {
    debug char* w = word;
    if (word in dictionary08) {
      uint code08 = dictionary08[word];
      writef("8:", code08, ' ');
      codes08[i8] = code08;
      i8++;
      eightCode[i] = true;
      continue;
    }
    if (word in dictionary16) {
      uint code16 = dictionary16[word];
      writef("16:", code16, ' ');
      codes16[i16] = code16;
      i16++;
      eightCode[i] = false;
      continue;
    }
    writefln("\nUnmatched word: ", word);
  }
  writefln();
}


void Decode()
{
  int i8 = 0;
  int i16 = 0;


  foreach(int i, bit b; eightCode) {
    char[] curWord;
    if (b == true) {
      curWord = lookup08[codes08[i8]];
      check[i] = curWord;
      writefln(curWord, ' ');
      i8++;
    }
    else {
      curWord = lookup16[codes16[i16]];
      check[i] = curWord;
      writefln(curWord, ' ');
      i16++;
    }
  }
  writefln();
  assert(check == text);
}

