#include "figure.h"

bool Figure::isFinishCellTrue(int xCoordinate,int yCoordinate, Figure ** figure)
{
	if(xCoordinate>7 || xCoordinate<0 || yCoordinate>7 || yCoordinate<0)
		return false;
	if(xCoordinate == coordinateX && yCoordinate == coordinateY)
		return false;

	for(int i=0;i<32;i++)
		if(figure[i]!=this)
			if(figure[i]->isFigureEat==false)
				if(figure[i]->coordinateX == xCoordinate && figure[i]->coordinateY == yCoordinate)
					if(figure[i]->whiteColour==whiteColour)
						return false;
	return true;
}
void Figure::putFigure(int xCoordinate,int yCoordinate)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps++;
	return;
}
void Figure::eatFigure(int xCoordinate,int yCoordinate,Figure **figure)
{
	for(int i=0;i<32;i++)
		if(figure[i]->coordinateX==xCoordinate && figure[i]->coordinateY==yCoordinate && figure[i]->isFigureEat==false)
		{
			figure[i]->isFigureEat=true;
			coordinateX=figure[i]->coordinateX;
			coordinateY=figure[i]->coordinateY;
			steps++;
			return;
		}
	return;
}