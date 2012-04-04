#pragma once
#include "desk.h"

#ifndef _player_h_
#define _player_h_

enum Winner
{
	white,
	black,
	twoWinner,
	nobody
};
class Player
{
private:
	Winner winner;
	bool whitePlayerTurnNow;
	bool checkWinner();
public:
	Desk desk;

	Player();
	bool makeTurn(const int startX,const int startY,const int finishX,const int finishY);
};

#endif