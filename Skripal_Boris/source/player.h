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
	void cancelTurn(int coordinateX, int coordinateY, int number);
	
public:
	Desk desk;
	//Desk getDesk();
	Player();
	bool makeTurn(const int startX,const int startY,const int finishX,const int finishY);
};

#endif