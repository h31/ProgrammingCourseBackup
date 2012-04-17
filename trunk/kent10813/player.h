#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "deck.h"

class player
	{
	protected:
		string name;
		deque <card> hand;
		deck mydeck;
	public:
		int bet;
		player ();
		
		virtual void EnterName ();
		
		virtual int MakeBets ();
		
		void takeCards ();
		
		virtual void show();
		
		void MoreOrStop ();
		
	};

#endif