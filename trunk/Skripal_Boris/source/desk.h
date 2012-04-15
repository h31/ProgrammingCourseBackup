//#pragma once

#ifndef _desk_h_
#define _desk_h_

class Figure;

#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
struct PlayingBoard
{
	TypeOfFigure figuresType;
	bool isFigureWhite;
	bool isCellWhite;
	Figure *figureOnCell;
};

class Desk
{
private:
	Figure *wKing;
	Figure *bKing;
	
	PlayingBoard **playingBoard;
	void refreshDesk();

	Figure **figure;
public:
	

	Desk();

	Figure* getFigure(const int number) const;

	void createNewDesk();
	void chanchePawn(const bool whiteColour);
	void setFigure(const int numberOfFigure,const  int type);
	bool checkMat(const bool whitePlayer);
	bool checkShah(const bool whitePlayer);
	bool castling(const int startX, const int startY,const int finishX,const  int finishY,const  bool whitePlayer);
	bool enPassant(const int startX,const  int startY,const int finishX, const int finishY,const  bool whitePlayer);
	//void makeFigureTurn(int number, int finishX, int finishY);
	~Desk();
};

#endif