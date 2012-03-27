#include "elephant.h"

Elephant::Elephant(int xCoordinate, int yCoordinate, bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
}

bool Elephant::canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,figure)==false)
		return false;
	if(abs(xCoordinate - coordinateX)!=(yCoordinate - coordinateY))
		return false;

	int xStep = (xCoordinate - coordinateX)/(abs(xCoordinate - coordinateX));
	int yStep = (yCoordinate - coordinateY)/(abs(yCoordinate - coordinateY));
	int startX = coordinateX;
	int startY = coordinateY;
	bool lineIsClear = true;

	while(abs(xCoordinate - coordinateX)>0)
	{
		startX+=xStep;
		startY+=yStep;

		for(int i=0;i<32;i++)
			if(figure[i]->isFigureEat!=true)
				if(figure[i]->coordinateX==startX)
					if(figure[i]->coordinateY == startY)
						return false;
	}
	cout<<"elephant"<<xCoordinate<<yCoordinate<<endl;
	return true;
}