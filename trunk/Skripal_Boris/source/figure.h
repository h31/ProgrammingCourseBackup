#ifndef _figure_h_
#define _figure_h_

#include <iostream>

//#include "playingBoard.h"
using namespace std;
enum TypeOfFigure
{
	pawn,
	king,
	queen,
	rook,
	knight,
	bishop
};

class Figure
{
public:
	int coordinateX;
	int coordinateY;
	int steps;
	bool whiteColour;
	bool isFigureEat;
	TypeOfFigure typeOfFigure;

	virtual bool canFigureTurn(int,int, Figure **)=0;

	bool isFinishCellTrue(int xCoordinate,int yCoordinate, Figure ** figure);
	void putFigure(int xCoordinate,int yCoordinate);
	void eatFigure(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif