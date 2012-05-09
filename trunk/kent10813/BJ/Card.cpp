#include "Card.h"

QString suits [4]= {"Diamonds","Hearts","Spades","Clubs"};
QString values [13]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};


void card::set_suit (Suits s)
	{
			su=s;
	}
void card::set_value (Values v)
	{
			val=v;
	}
QString card::get_suit ()
	{
			return suits[su];
	}
QString card::get_score()
	{
			return values [val];
	}

