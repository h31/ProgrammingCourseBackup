#include "rook.h"

Rook::Rook(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = rook;

	symbol ='R';
}

bool Rook::canFigureTurn(const int xCoordinate,const int yCoordinate,const Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate, desk)==false)
		return false;
	if((xCoordinate - coordinateX)!=0 && (yCoordinate - coordinateY)!=0)
		return false;

	int stepOfRook,startX,startY;
	bool lineIsClear = true;

	if((xCoordinate - coordinateX)!=0)
		stepOfRook=abs(xCoordinate-coordinateX)/(xCoordinate - coordinateX);
	else
		stepOfRook = abs(yCoordinate - coordinateY)/(yCoordinate - coordinateY);
	startX = coordinateX;
	startY = coordinateY;

	if((xCoordinate - coordinateX)!=0)
		while(lineIsClear==true && abs(startX-xCoordinate)>1)
		{
			startX+=stepOfRook;
			for(int i=0;i<32;i++)
				if(desk.getFigure(i)->isEat()==false)     
					if(desk.getFigure(i)->getX() == startX && desk.getFigure(i)->getY()==coordinateY)
					{
						lineIsClear=false;
						break;
					}
		}

	if((yCoordinate - coordinateY)!=0)
		while(lineIsClear==true && abs(startY-yCoordinate)>1)
		{
			startY+=stepOfRook;
			for(int i=0;i<32;i++)
				if(desk.getFigure(i)->isEat()==false)
					if(desk.getFigure(i)->getX() == coordinateX && desk.getFigure(i)->getY()==startY)
					{
						lineIsClear=false;
						break;
					}
		}

	if(lineIsClear == true)
			return true;
	//cout<<"rook"<<xCoordinate<<yCoordinate<<endl;
	return false;
}

void Rook::printFigure(QPainter &painter)
{
    QPixmap figureIcon;
    if(whiteColour==true)
        figureIcon.load("rookwhite.png");
    else
       figureIcon.load("rookblack.png");
    int x = 78*coordinateX-30;
    int y = 78*coordinateY-11;
    painter.drawPixmap(x,y,figureIcon);
    return;
}
