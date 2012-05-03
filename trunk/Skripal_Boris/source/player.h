#pragma once


#ifndef _player_h_
#define _player_h_

#include <QtGui>

#include "desk.h"
#include "test.h"

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

	friend class Test;
};

#endif
