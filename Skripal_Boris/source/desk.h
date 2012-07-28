//#pragma once

#ifndef _desk_h_
#define _desk_h_

class Figure;
#include <QtGui>
#include <vector>

#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

#include "chanchepawn.h"
#include "docastling.h"

struct PlayingBoard
{
	TypeOfFigure figuresType;
	bool isFigureWhite;
	bool isCellWhite;
	Figure *figureOnCell;
};

struct TurnCoordinate
{
    int startX;
    int startY;
    int finishX;
    int finishY;

    TurnCoordinate(int sX, int sY, int fX, int fY);

    friend ostream& operator << (ostream &out,const TurnCoordinate &T);
};

class Desk: public QObject
{
   Q_OBJECT
private:
	Figure *wKing;
	Figure *bKing;
	
    vector <TurnCoordinate> turnVec;

	PlayingBoard **playingBoard;
	Figure **figure;

	void cancelTurn(const int coordinateX, const int coordinateY, const int number);

	void refreshPlayingBoard();
	void changePawn(const bool whiteColour);
	void setFigure(const int numberOfFigure,const  int type);
	bool castling(const int startX, const int startY,const int finishX,const  int finishY,const  bool whitePlayer);
	bool enPassant(const int startX,const  int startY,const int finishX, const int finishY,const  bool whitePlayer);
signals:
   // void checkShah();
    void printShah();
public:
	Desk();

	Figure* getFigure(const int number) const;	
	void createNewDesk();
	bool checkMat(const bool whitePlayer);
    bool checkShah(const bool whitePlayer);
	bool makeFigureTurn(const int startX,const int startY,const int finishX,const int finishY, const bool whitePlayerTurn);

    void setTurnVecElem(TurnCoordinate coord);
    TurnCoordinate getTurnVecElem(int id);
    int getTurnVecSize();
    void clearTurnVec();

    void printPlayingBoard();
	~Desk();

	friend class Test;
};

#endif
