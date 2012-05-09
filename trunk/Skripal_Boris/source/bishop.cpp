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

    if(abs(xCoordinate-coordinateX)==1)
        return true;
    while((xCoordinate - startX)!=1)
	{
		startX+=xStep;
		startY+=yStep;

		for(int i=0;i<32;i++)
			if(desk.getFigure(i)->isEat()==false)
				if(desk.getFigure(i)->getX()==startX)
					if(desk.getFigure(i)->getY() == startY)
						return false;
	}
//    for(int i=0;i<32;i++)
//        if(desk.getFigure(i)->getColour()!=whiteColour && desk.getFigure(i)->isEat()==false)
//            return true;
	return true;
}

void Bishop::printFigure(QPainter &painter)
{
    QPixmap figureIcon;
    if(whiteColour==true)
       figureIcon.load("bishopwhite.png");
    else
       figureIcon.load("bishopblack.png");
    int x = 78*coordinateX-30;
    int y = 78*coordinateY-11;
    painter.drawPixmap(x,y,figureIcon);
    return;
}
