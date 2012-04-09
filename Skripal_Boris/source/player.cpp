#include "player.h"

Player::Player()
{
	winner = nobody;
	whitePlayerTurnNow = true;
}

bool Player::makeTurn(const int startX,const int startY,const int finishX,const int finishY)
{
	//checkWinner();

	if(desk.checkShah(whitePlayerTurnNow)==true)
		cout<<"Shah"<<endl;
	if(desk.castling(startX,startY,finishX,finishY,whitePlayerTurnNow)==true)
	{
		cout<<"Castling is true"<<endl;
		return true;
	}
	if(desk.enPassant(startX,startY,finishX,finishY,whitePlayerTurnNow)==true)
	{
		cout<<"en passant is true"<<endl;
		return true;
	}
	int numberOfFigure= -1;
	for(int i=0;i<32;i++)
		if(desk.figure[i]->getX()==startX && desk.figure[i]->getY()==startY)
			numberOfFigure=i;
	if(numberOfFigure ==-1)
		return false;
	if(desk.figure[numberOfFigure]->getColour()!=whitePlayerTurnNow)
		return false;

	if(desk.figure[numberOfFigure]->canFigureTurn(finishX,finishY,desk)==false)
		return false;
	else
	{
		for(int i=0;i<32;i++)
			if(desk.figure[i]->getX() == finishX &&  desk.figure[i]->getY()== finishY && desk.figure[i]->isEat()==false)
				desk.figure[numberOfFigure]->eatFigure(finishX,finishY,desk);
			else
				desk.figure[numberOfFigure]->putFigure(finishX,finishY);
		desk.chanchePawn(whitePlayerTurnNow);
		return true;
	}

	return false;
}

//Desk Player::getDesk()
//{
//	return desk;
//}