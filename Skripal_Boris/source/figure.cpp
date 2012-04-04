#include "figure.h"
#include "desk.h"

bool Figure::isFinishCellTrue(const int xCoordinate,const int yCoordinate,const Desk& desk)
{
	if(xCoordinate>7 || xCoordinate<0 || yCoordinate>7 || yCoordinate<0)
		return false;
	if(xCoordinate == coordinateX && yCoordinate == coordinateY)
		return false;

	for(int i=0;i<32;i++)
		if(desk.figure[i]!=this)
			if(desk.figure[i]->isFigureEat==false)
				if(desk.figure[i]->coordinateX == xCoordinate && desk.figure[i]->coordinateY == yCoordinate)
					if(desk.figure[i]->whiteColour==whiteColour)
						return false;
	return true;
}
void Figure::putFigure(const int xCoordinate,const int yCoordinate)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps++;
	return;
}
void Figure::eatFigure(const int xCoordinate,const int yCoordinate,Desk &desk)
{
	for(int i=0;i<32;i++)
		if(desk.figure[i]->coordinateX==xCoordinate && desk.figure[i]->coordinateY==yCoordinate && desk.figure[i]->isFigureEat==false)
		{
			desk.figure[i]->isFigureEat=true;
			coordinateX=desk.figure[i]->coordinateX;
			coordinateY=desk.figure[i]->coordinateY;
			steps++;
			return;
		}
	return;
}

	int Figure::getX()
	{
		return coordinateX;
	}

	int Figure::getY()
	{
		return coordinateY;
	}

	int Figure::getStep()
	{
		return steps;
	}

	TypeOfFigure Figure::getType()
	{
		return typeOfFigure;
	}

	bool Figure::getColour()
	{
		return whiteColour;
	}
	bool Figure::isEat()
	{
		return isFigureEat;
	}

	void Figure::setX(int x)
	{
		coordinateX=x;
		return;
	}
	void Figure::setY(int y)
	{
		coordinateY=y;
		return;
	}
	void Figure::increaceSteps()
	{
		steps++;
		return;
	}
	void Figure::eatFigure()
	{
		isFigureEat=true;
		return;
	}