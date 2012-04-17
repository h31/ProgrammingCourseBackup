#ifndef _DEALER_H_
#define _DEALER_H_
#include "player.h"

class Dealer : public player
	{
	public:
		
		void EnterName ();
		int MakeBets();
		void show();
	};


#endif