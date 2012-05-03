#include "queen.h"

Queen::Queen(const int xCoordinate, const int yCoordinate, const bool whiteFigure)
{
	coordinateX = xCoordinate;
	coordinateY = yCoordinate;
	steps =0;
	whiteColour = whiteFigure;
	isFigureEat = false;
	typeOfFigure = queen;

	symbol='Q';
}

bool Queen::canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk)
{
	if(isFinishCellTrue(xCoordinate,yCoordinate,desk)==false)
		return false;
	if(abs(coordinateX - xCoordinate)!=abs(coordinateY-yCoordinate))
		if(abs(coordinateX-xCoordinate)!=0 && (coordinateY-yCoordinate)!=0)
			return false;
	int stepX,stepY;
	if(yCoordinate==coordinateY)
		stepY=0;
	else
		stepY=(yCoordinate-coordinateY)/abs(yCoordinate-coordinateY);
	if(xCoordinate==coordinateX)
		stepX=0;
	else
		stepX=(xCoordinate-coordinateX)/abs(xCoordinate-coordinateX);

	int startX = coordinateX;
	int startY = coordinateY;

	while(abs(startX-xCoordinate)>1 || abs(startY-yCoordinate)>1)
	{
		startX+=stepX;
		startY+=stepY;
		for(int i=0;i<32;i++)
			if(desk.getFigure(i)->isEat()==false)
				if(desk.getFigure(i)->getX()==startX && desk.getFigure(i)->getY() == startY)
					return false;
	}
	//cout<<"queen"<<xCoordinate<<yCoordinate<<endl;
	return true;
}

void Queen::printFigure(QPainter &painter)
{
    QPixmap figureIcon;
    if(whiteColour==true)
       figureIcon.load("queenwhite.png");
    else
        figureIcon.load("queenblack.png");
    int x = 78*coordinateX-30;
    int y = 78*coordinateY-11;
    painter.drawPixmap(x,y,figureIcon);
    return;
}
