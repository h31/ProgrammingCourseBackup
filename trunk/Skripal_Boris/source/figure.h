#ifndef _figure_h_
#define _figure_h_

#include <iostream>
#include <QtGui>

using namespace std;

enum TypeOfFigure
{
	pawn,
	king,
	queen,
	rook,
	knight,
	bishop,
	none
};

class Desk;

class Figure: public QObject
{
   // Q_OBJECT
protected:
	int coordinateX;
	int coordinateY;
	int steps;
	bool whiteColour;
	bool isFigureEat;
	TypeOfFigure typeOfFigure;
	
public:
	char symbol;
	int getX();
	int getY();
	int getStep();
	TypeOfFigure getType();
	bool getColour();
	bool isEat();

	void setX(const int x);
	void setY(const int y);
	void increaceSteps(const bool plus);
	void eatFigure(const bool eat);

	virtual bool canFigureTurn(const int,const int,const Desk &)=0;
    virtual void printFigure(QPainter &)=0;

	bool isFinishCellTrue(const int xCoordinate,const int yCoordinate,const Desk& desk);
	void putFigure(const int xCoordinate,const int yCoordinate);
	void eatFigure(const int xCoordinate,const int yCoordinate, Desk &desk);
};

#endif
