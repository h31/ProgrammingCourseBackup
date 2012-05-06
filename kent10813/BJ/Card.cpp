#include "Card.h"

string suits [4]= {"Diamonds","Hearts","Spades","Clubs"};
string values [13]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};


void card::set_suit (Suits s)
	{
			su=s;
	}
void card::set_value (Values v)
	{
			val=v;
	}
string card::get_suit ()
	{
			return suits[su];
	}
string card::get_score ()
	{
			return values [val];
	}
