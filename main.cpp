#include <iostream>
#include "world.h"

//tester klas systemu

int main()
{
	Cworld delmirum; //swiat delmirum (mroczne krolestwo), 
			    //przykladowo 10 na 10 theritoriow ;} na 200 graczy styka lekko;}
	Cworld crealis(1,1,3,3,1.2); //swiat crealis (dolina gluchej ciszy -noob'landia)
	//Cworld umbra(255,255,255,255,0); //ogrom, plus zero grawitacji.. czyli nie miejsce dla smiertelnikow :}
	
	//std::vector<Cworld> delmirum;
	
	crealis.name="crealis";
	crealis.theritory.name="neomis";
	crealis.theritory.place.name="cathalith village";
	crealis.theritory.place.map.name="alley of the cathalith";
	
	//modyfikujemy pozycje w crealis
	
	delmirum.character.push_back( Ccharacter() ); //dodanie nowego gracza na koniec wektora dynamicznej listy graczy
	
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
	
	return 0;
}
