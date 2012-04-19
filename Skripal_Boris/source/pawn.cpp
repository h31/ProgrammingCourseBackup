#include "pawn.h"

Pawn::Pawn(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = pawn;

	symbol='P';
}

bool Pawn::canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,desk)==false)
		return false;
	if(abs(yCoordinate - coordinateY)>2)
		return false;
	bool pawnEat = false;
	for(int i=0;i<32;i++)
		if(desk.getFigure(i)->isEat()!=true)
			if(desk.getFigure(i)->getX() == xCoordinate)
				if(desk.getFigure(i)->getY() == yCoordinate)
					if(desk.getFigure(i)->getColour()!=whiteColour)
					{
						pawnEat=true;
						break;
					}
	if(pawnEat==false)
		for(int i=0;i<32;i++)
			if(desk.getFigure(i)->isEat()==false)
				if(desk.getFigure(i)->getX()==coordinateX)
					if(desk.getFigure(i)->getY()==coordinateY+(abs(coordinateY-yCoordinate)/(yCoordinate-coordinateY)))
						return false;

	if(pawnEat==false)
		if(xCoordinate == coordinateX)
		{
			if(whiteColour==true && (coordinateY - yCoordinate)==-2 )
				if(steps==0)
					return true;
			if(whiteColour==false && (coordinateY - yCoordinate)==2)
				if(steps==0)
					return true;
			if(whiteColour==true && (coordinateY - yCoordinate)==-1 )
					return true;
			if(whiteColour==false && (coordinateY - yCoordinate)==1)
					return true;
		}
	if(pawnEat==true)
		if(abs(xCoordinate - coordinateX)==1)
		{
			if(whiteColour==true && (coordinateY - yCoordinate)==-1 )
					return true;
			if(whiteColour==false && (coordinateY - yCoordinate)==1)
					return true;
		}
	cout<<"pawn"<<xCoordinate<<yCoordinate<<endl;
	return false;
}
