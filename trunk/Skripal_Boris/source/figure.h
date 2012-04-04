#ifndef _figure_h_
#define _figure_h_

#include <iostream>

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

class Desk;

class Figure
{
protected:
	int coordinateX;
	int coordinateY;
	int steps;
	bool whiteColour;
	bool isFigureEat;
	TypeOfFigure typeOfFigure;
public:
	int getX();
	int getY();
	int getStep();
	TypeOfFigure getType();
	bool getColour();
	bool isEat();

	void setX(int x);
	void setY(int y);
	void increaceSteps();
	void eatFigure();

	virtual bool canFigureTurn(const int,const int,const Desk &)=0;

	bool isFinishCellTrue(const int xCoordinate,const int yCoordinate,const Desk& desk);
	void putFigure(const int xCoordinate,const int yCoordinate);
	void eatFigure(const int xCoordinate,const int yCoordinate, Desk &desk);
};

#endif