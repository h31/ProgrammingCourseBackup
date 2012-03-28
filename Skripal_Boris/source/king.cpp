#include "king.h"

King::King(int xCoordinate, int yCoordinate, bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = king;
}

bool King::canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,figure)==false)
		return false;
	if(abs(xCoordinate - coordinateX)>1 || abs(yCoordinate - coordinateY)>1)
		return false;


	cout<<"king"<<xCoordinate<<yCoordinate<<endl;
	return false;
}
