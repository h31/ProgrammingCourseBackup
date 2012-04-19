#include "figure.h"
#include "desk.h"

bool Figure::isFinishCellTrue(const int xCoordinate,const int yCoordinate,const Desk& desk)
{
	if(xCoordinate>8 || xCoordinate<0 || yCoordinate>8 || yCoordinate<0)
		return false;
	if(xCoordinate == coordinateX && yCoordinate == coordinateY)
		return false;

	for(int i=0;i<32;i++)
		if(desk.getFigure(i)!=this)
			if(desk.getFigure(i)->isFigureEat==false)
				if(desk.getFigure(i)->coordinateX == xCoordinate && desk.getFigure(i)->coordinateY == yCoordinate)
					if(desk.getFigure(i)->whiteColour==whiteColour)
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
		if(desk.getFigure(i)->coordinateX==xCoordinate && desk.getFigure(i)->coordinateY==yCoordinate && desk.getFigure(i)->isFigureEat==false)
		{
			desk.getFigure(i)->isFigureEat=true;
			coordinateX=desk.getFigure(i)->coordinateX;
			coordinateY=desk.getFigure(i)->coordinateY;
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

	void Figure::setX(const int x)
	{
		coordinateX=x;
		return;
	}
	void Figure::setY(const int y)
	{
		coordinateY=y;
		return;
	}
	void Figure::increaceSteps(const bool plus)
	{
		if(plus==true)
			steps++;
		else
			steps--;
		return;
	}
	void Figure::eatFigure(const bool eat)
	{
		if (eat == true)
			isFigureEat=true;
		else
			isFigureEat=false;
		return;
	}
