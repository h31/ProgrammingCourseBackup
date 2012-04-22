#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "deck.h"

class player
	{
	protected:
		
		deque <card> hand;
		deck mydeck;
		
	public:
		int score;
		int bet;
		player ();
		
		
		virtual int makeBets ();
		void takeCards ();
		virtual void show();
		int countScore ();
		
	};

#endif