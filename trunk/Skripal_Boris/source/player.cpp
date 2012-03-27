#include "player.h"

Player::Player()
{
	winner = nobody;
	whitePlayerTurnNow = true;
}

bool Player::makeTurn(int startX, int startY,int finishX, int finishY)
{
	//checkWinner();

	/*if(desk.checkShah(whitePlayerTurnNow)==true)
		cout<<"Shah"<<endl;*/
	int numberOfFigure= -1;
	for(int i=0;i<32;i++)
		if(desk.figure[i]->coordinateX==startX && desk.figure[i]->coordinateY==startY)
			numberOfFigure=i;
	if(numberOfFigure ==-1)
		return false;
	if(desk.figure[numberOfFigure]->whiteColour!=whitePlayerTurnNow)
		return false;

	if(desk.figure[numberOfFigure]->canFigureTurn(finishX,finishY,desk.figure)==false)
		return false;
	else
	{
		for(int i=0;i<32;i++)
			if(desk.figure[i]->coordinateX == finishX &&  desk.figure[i]->coordinateY== finishY && desk.figure[i]->isFigureEat==false)
				desk.figure[numberOfFigure]->eatFigure(finishX,finishY,desk.figure);
			else
				desk.figure[numberOfFigure]->putFigure(finishX,finishY);
		return true;
	}

	return false;
}