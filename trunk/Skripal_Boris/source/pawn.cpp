#include "pawn.h"

Pawn::Pawn(int xCoordinate, int yCoordinate, bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = pawn;
}

bool Pawn::canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,figure)==false)
		return false;
	if(abs(yCoordinate - coordinateY)>2)
		return false;
	bool pawnEat = false;
	for(int i=0;i<32;i++)
		if(figure[i]->isFigureEat!=true)
			if(figure[i]->coordinateX == xCoordinate)
				if(figure[i]->coordinateY == yCoordinate)
					if(figure[i]->whiteColour!=whiteColour)
						pawnEat=true;
	if(pawnEat==false)
		for(int i=0;i<32;i++)
			if(figure[i]->isFigureEat==false)
				if(figure[i]->coordinateX==coordinateX)
					if(figure[i]->coordinateY==coordinateY+(abs(coordinateY-yCoordinate)/(yCoordinate-coordinateY)))
						return false;

	if(pawnEat==false)
		if(xCoordinate == coordinateX)
		{
			if(whiteColour==true && (coordinateY - yCoordinate)==2 )
				if(steps==0)
					return true;
			if(whiteColour==false && (coordinateY - yCoordinate)==-2)
				if(steps==0)
					return true;
			if(whiteColour==true && (coordinateY - yCoordinate)==1 )
					return true;
			if(whiteColour==false && (coordinateY - yCoordinate)==-1)
					return true;
		}
	if(pawnEat==true)
		if(abs(xCoordinate - coordinateX)==1)
		{
			if(whiteColour==true && (coordinateY - yCoordinate)==1 )
					return true;
			if(whiteColour==false && (coordinateY - yCoordinate)==-1)
					return true;
		}
	cout<<"pawn"<<xCoordinate<<yCoordinate<<endl;
	return false;
}
