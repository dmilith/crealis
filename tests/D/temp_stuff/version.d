import std.stdio;

const char[] salutation = "Hi";
const char[] negative = "No";

version(Espanol) 
{
    const char[] salutation = "Hola";
    const char[] negative = "No";
} 

version(Francais)
{
    const char[] salutation = "Bonjour";
    const char[] negative = "Non";
} 

version(Deutsch)  
{
    const char[] salutation = "Hallo";
    const char[] negative = "Nein";
} 

int main()
{
    writef(salutation);
    return 0;
}

