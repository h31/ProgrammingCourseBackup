#include "queen.h"

Queen::Queen(int xCoordinate, int yCoordinate, bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = queen;
}

bool Queen::canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,figure)==false)
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
			if(figure[i]->isFigureEat==false)
				if(figure[i]->coordinateX==startX && figure[i]->coordinateY == startY)
					return false;
	}
	cout<<"queen"<<xCoordinate<<yCoordinate<<endl;
	return false;
}
