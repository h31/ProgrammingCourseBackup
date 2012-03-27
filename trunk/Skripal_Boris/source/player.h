#pragma once
#include "playingBoard.h"

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
public:
	Desk desk;
	Winner winner;
	bool whitePlayerTurnNow;

	Player();
	bool makeTurn(int startX, int startY,int finishX, int finishY);
	bool checkWinner();

	
};

#endif