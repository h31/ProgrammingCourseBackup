#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include <iostream>
using namespace std;

enum Suits {diamonds, hearts, spades, clubs};
enum Values {two, three, four, five, six, seven, eight, nine, ten, jack,queen, king, ace};

class card
{
	private:
		Suits su;
		Values val;
	public:
		void set_suit (Suits s);
		
		void set_value (Values v);
		
		string get_suit ();
		
		string get_score ();
		
};

#endif