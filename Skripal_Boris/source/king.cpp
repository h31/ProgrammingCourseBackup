#include "king.h"

King::King(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = king;

	symbol='K';
}

bool King::canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,desk)==false)
		return false;
	if(abs(xCoordinate - coordinateX)>1 || abs(yCoordinate - coordinateY)>1)
		return false;


	cout<<"king"<<xCoordinate<<yCoordinate<<endl;
	return false;
}
