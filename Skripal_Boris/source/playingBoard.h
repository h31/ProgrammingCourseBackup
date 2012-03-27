#pragma once

#ifndef _playingBoard_h_
#define _playingBoard_h_
#include "figure.h"

#include "elephant.h"
#include "horse.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"


class Desk
{
public:
	Figure **figure;

	Desk();
	void createNewDesk();
	/*bool getFigure(int x, int y, bool whiteColour);
	bool getFigure(int x, int y);*/
	bool setFigure(int x, int y, bool whiteColour);
	bool checkMat(bool whitePlayer);
	bool checkShah(bool whitePlayer);
	bool Castling(int xCoordinate,int yCoordinate);
	void makeTurn(int number, int finishX, int finishY);
	~Desk();
};

#endif