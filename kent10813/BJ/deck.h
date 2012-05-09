#ifndef _DECK_H_
#define _DECK_H_

#include "Card.h"
#include "ctime"
#include <deque>
#include <algorithm>


class deck 
	{
	private:
		deque<card> Deck;
	public:

		card crd;
		void create_deck ();
		
		void shuffle ();
		
		card pull_card ();
		
	};


#endif
