#include "bishop.h"

Bishop::Bishop(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = bishop;

	symbol='E';
}

bool Bishop::canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,desk)==false)
		return false;
	if(abs(xCoordinate - coordinateX)!=abs(yCoordinate - coordinateY))
		return false;

	int xStep = (xCoordinate - coordinateX)/(abs(xCoordinate - coordinateX));
	int yStep = (yCoordinate - coordinateY)/(abs(yCoordinate - coordinateY));
	int startX = coordinateX;
	int startY = coordinateY;
	bool lineIsClear = true;

	while((xCoordinate - startX)!=0)
	{
		startX+=xStep;
		startY+=yStep;

		for(int i=0;i<32;i++)
			if(desk.getFigure(i)->isEat()==false)
				if(desk.getFigure(i)->getX()==startX)
					if(desk.getFigure(i)->getY() == startY)
						return false;
	}
	cout<<"bishop"<<xCoordinate<<yCoordinate<<endl;
	return true;
}