#include "figure.h"

#include <iostream>

Figure::Figure()
{
	steps =0;
}

bool Figure::canPawnTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY,const bool whitePlayer)
{
	if(whitePlayer==true)
		if (desk[startX][startY].whiteFigure==true)
		{
			if(desk[finishX][finishY].type==emptyCell)
				if(startX-finishX==0)
				{
					if(desk[startX][startY].steps==0)
						if(finishY-startY==1 || finishY-startY==2)
							return true;
					if(desk[startX][startY].steps>0)
						if(finishY-startY==1)
							return true;
				}
			if(desk[finishX][finishY].type!=emptyCell || desk[finishX][finishY].whiteFigure!=true)
				if(abs(startX-finishX)==1 && finishY-startY ==1)
					return true;
		}

		if(whitePlayer==false)
		if (desk[startX][startY].whiteFigure==false)
		{
			if(desk[finishX][finishY].type==emptyCell)
				if(startX-finishX==0)
				{
					if(desk[startX][startY].steps==0)
						if(startY-finishY==1 || startY-finishY==2)
							return true;
					if(desk[startX][startY].steps>0)
						if(startY-finishY==1)
							return true;
				}
			if(desk[finishX][finishY].type!=emptyCell || desk[finishX][finishY].whiteFigure!=false)
				if(abs(startX-finishX)==1 && startY-finishY ==1)
					return true;
		}
	return false;
}

bool Figure::canKingTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY)
{
	if(abs(startX-finishX)<2 && abs(startY-finishY)<2)
	{
		if(desk[finishX][finishY].type==emptyCell)
			return true;
		if(desk[finishX][finishY].type!=emptyCell)
			if(desk[startX][startY].whiteFigure!=desk[finishX][finishY].whiteFigure)
				return true;
	}
	return false;
}

bool Figure::canRookTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY)
{
	int startPoint, finishPoint,line;
	if(startX-finishX==0)
	{
		startPoint=startY;
		finishPoint=finishY;
		line = startX;
	}
	else
	{
		startPoint=startX;
		finishPoint = finishX;
		line = startY;
	}
	bool attackLineClear=true;
	int step = (finishPoint-startPoint)/abs(finishPoint-startPoint);
	startPoint+=step;
	if(startX!=finishX)
		for(startPoint;abs(startPoint-finishPoint)>0;startPoint+=step)
			if(desk[startPoint][line].type!=emptyCell)
				attackLineClear = false;
	if(startY!=finishY)
		for(startPoint;abs(startPoint-finishPoint)>0;startPoint+=step)
			if(desk[line][startPoint].type!=emptyCell)
				attackLineClear = false;
	if(attackLineClear==true)
		if(abs(startX-finishX)==0 && abs(finishY-startY)!=0 || abs(startX-finishX)!=0 && abs(finishY-startY)==0)
		{
			if(desk[finishX][finishY].type==emptyCell)
				return true;
			if(desk[finishX][finishY].type!=emptyCell)
				if(desk[finishX][finishY].whiteFigure!=desk[startX][startY].whiteFigure)
					return true;
		}
	return false;
}

bool Figure::canQueenTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY)
{
	if(canRookTurn(desk,startX,startY,finishX,finishY)==true)
		return true;
	if(canElephantTurn(desk,startX,startY,finishX,finishY)==true)
		return true;
	return false;
}

bool Figure::canHourseTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY)
{
	if(abs(startX-finishX)==1 && abs(startY - finishY)==2 || abs(startX-finishX)==2 && abs(startY - finishY)==1)
	{
		if(desk[finishX][finishY].type == emptyCell)
			return true;
		if(desk[finishX][finishY].type != emptyCell)
			if(desk[finishX][finishY].whiteFigure != desk[startX][startY].whiteFigure)
				return true;
	}
	return false;
}

bool Figure::canElephantTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY)
{
	int x=startX;
	int y=startY;
	bool isLineClear=true;
	int stepX, stepY;
	stepX = (finishX-startX)/abs(finishX-startX);
	stepY = (finishY-startY)/abs(finishY-startY);

	while(abs(finishX-x)>0)
	{
		x+=stepX;
		y+=stepY;
		if(desk[x][y].type!=emptyCell)
			isLineClear = false;
	}

	if(isLineClear==true)
		if(abs(startX-finishX)==abs(startY-finishY))
		{
			if(desk[finishX][finishY].type==emptyCell)
				return true;
			if(desk[finishX][finishY].type!=emptyCell)
				if(desk[startX][startY].whiteFigure!=desk[startX][startY].whiteFigure)
					return true;
		}
	return false;
}

