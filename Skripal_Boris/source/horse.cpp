#include "horse.h"

Horse::Horse(int xCoordinate, int yCoordinate, bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
}

bool Horse::canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,figure)==false)
		return false;
	if(abs(xCoordinate - coordinateX)==1 && abs(yCoordinate - coordinateY) ==3)
		return true;
	if(abs(xCoordinate - coordinateX)==3 && abs(yCoordinate - coordinateY) ==1)
		return true;
	cout<<"horse"<<xCoordinate<<yCoordinate<<endl;
	return false;
}