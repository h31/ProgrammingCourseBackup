//#pragma once

#ifndef _desk_h_
#define _desk_h_

class Figure;
#include <QtGui>

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
	Figure **figure;

	void cancelTurn(const int coordinateX, const int coordinateY, const int number);

	void refreshPlayingBoard();
	void chanchePawn(const bool whiteColour);
	void setFigure(const int numberOfFigure,const  int type);
	bool castling(const int startX, const int startY,const int finishX,const  int finishY,const  bool whitePlayer);
	bool enPassant(const int startX,const  int startY,const int finishX, const int finishY,const  bool whitePlayer);
public:
	Desk();

	Figure* getFigure(const int number) const;	
	void createNewDesk();
	bool checkMat(const bool whitePlayer);
	bool checkShah(const bool whitePlayer);
	bool makeFigureTurn(const int startX,const int startY,const int finishX,const int finishY, const bool whitePlayerTurn);

	void printPlayingBoard();\
	~Desk();

	friend class Test;
};

#endif
