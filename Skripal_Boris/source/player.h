#pragma once


#ifndef _player_h_
#define _player_h_

#include <QtGui>

#include "desk.h"
#include "test.h"
//#include "mainwindow.h"


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

     void insertWhitePlayerTurnNow();
public:
    Desk *desk;
	//Desk getDesk();
	Player();
    bool getWhitePlayerTurnNow();
    void newGame();
    //bool makeGame();
    void makePlayerTurn(int startX, int startY, int finishX, int finishY);

	friend class Test;
};

#endif
