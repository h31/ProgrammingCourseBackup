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
        card crd;
        void shuffle ();
    public:
        void create_deck ();
         card pull_card ();
		
	};


#endif
