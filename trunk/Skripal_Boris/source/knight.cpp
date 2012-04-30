#include "knight.h"

Knight::Knight(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = knight;

	symbol='H';
}

bool Knight::canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,desk)==false)
		return false;
	if(abs(xCoordinate - coordinateX)==1 && abs(yCoordinate - coordinateY) ==2)
		return true;
	if(abs(xCoordinate - coordinateX)==2 && abs(yCoordinate - coordinateY) ==1)
		return true;
	//cout<<"knight"<<xCoordinate<<yCoordinate<<endl;
	return false;
}