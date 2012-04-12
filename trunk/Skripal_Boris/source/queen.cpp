#include "queen.h"

Queen::Queen(const int xCoordinate, const int yCoordinate, const bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = queen;
}

bool Queen::canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,desk)==false)
		return false;
	if(abs(xCoordinate - coordinateX)!=0 && abs(yCoordinate - coordinateY)!=0 && abs(coordinateX - xCoordinate)!=abs(coordinateY- yCoordinate))
		return false;
	int stepY=abs(yCoordinate-coordinateY)/(yCoordinate-coordinateY);
	int stepX=abs(xCoordinate-coordinateX)/(xCoordinate-coordinateX);

	int startX = coordinateX;
	int startY = coordinateY;

	while(abs(startX-xCoordinate)>1)
	{
		startX+=stepX;
		startY+=stepY;
		for(int i=0;i<32;i++)
			if(desk.getFigure(i)->isEat()==false)
				if(desk.getFigure(i)->getX()==startX && desk.getFigure(i)->getY() == startY)
					return false;
	}
	cout<<"queen"<<xCoordinate<<yCoordinate<<endl;
	return false;
}
