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
	void printWinner();
	void newGame();	
public:
	Desk desk;
	//Desk getDesk();
	Player();
	bool makeGame();
};

#endif