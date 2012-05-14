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
class Player : public QObject
{
     Q_OBJECT
private:
	Winner winner;
    int whitePlayerWins;
    int blackPlayerWins;

	bool whitePlayerTurnNow;
	bool checkWinner();
	void printWinner();

     void insertWhitePlayerTurnNow();
signals:
     void printShah();
     void printFalseTurn();
     void printMat();
public:
    Desk *desk;
	Player();
    bool getWhitePlayerTurnNow();
    int getWhitePlayerWins();
    int getBlackPlayerWins();
    void plusWinner(bool whitePlayer);
    void newGame();
    Winner getWinner();
    void makePlayerTurn(int startX, int startY, int finishX, int finishY);

	friend class Test;
};

#endif
