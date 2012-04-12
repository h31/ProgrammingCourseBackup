#include "player.h"

Player::Player()
{
	winner = nobody;
	whitePlayerTurnNow = true;

}

bool Player::makeTurn(const int startX,const int startY,const int finishX,const int finishY)
{
	//checkWinner();
	int numberOfFirstFigure= -1;
	int numberOfSecondFigure =-1;
	for(int i=0;i<32;i++)
		if(desk.getFigure(i)->getX()==startX && desk.getFigure(i)->getY()==startY)
			numberOfFirstFigure=i;
	if(numberOfFirstFigure ==-1)
		return false;
	for(int i=0;i<32;i++)
		if(desk.getFigure(i)->getX()==startX && desk.getFigure(i)->getY()==startY)
			numberOfSecondFigure=i;

	if(desk.checkShah(whitePlayerTurnNow)==true)
	{
		checkWinner();
		cout<<"Shah"<<endl;
	}
	if(desk.castling(startX,startY,finishX,finishY,whitePlayerTurnNow)==true)
	{
		if(desk.checkShah(whitePlayerTurnNow)==true)
		{
			cancelTurn(startX,startY,numberOfFirstFigure);
			cancelTurn(finishX,finishY,numberOfSecondFigure);
			return false;
		}
		cout<<"Castling is true"<<endl;
		return true;
	}
	if(desk.enPassant(startX,startY,finishX,finishY,whitePlayerTurnNow)==true)
	{
		if(desk.checkShah(whitePlayerTurnNow)==true)
		{
			cancelTurn(startX,startY,numberOfFirstFigure);
			cancelTurn(finishX,finishY,numberOfSecondFigure);
			return false;
		}
		cout<<"en passant is true"<<endl;
		return true;
	}
	
	
	if(desk.getFigure(numberOfFirstFigure)->getColour()!=whitePlayerTurnNow)
		return false;

	if(desk.getFigure(numberOfFirstFigure)->canFigureTurn(finishX,finishY,desk)==false)
		return false;
	else
	{
		for(int i=0;i<32;i++)
			if(desk.getFigure(i)->getX() == finishX &&  desk.getFigure(i)->getY()== finishY && desk.getFigure(i)->isEat()==false)
				desk.getFigure(numberOfFirstFigure)->eatFigure(finishX,finishY,desk);
			else
				desk.getFigure(numberOfFirstFigure)->putFigure(finishX,finishY);
		if(desk.checkShah(whitePlayerTurnNow)==true)
		{
			cancelTurn(startX,startY,numberOfFirstFigure);
			cancelTurn(finishX,finishY,numberOfSecondFigure);
			return false;
		}
		desk.chanchePawn(whitePlayerTurnNow);
		return true;
	}

	return false;
}

bool Player::checkWinner()
{
	if(desk.checkMat(whitePlayerTurnNow)==true)
	{
		if(whitePlayerTurnNow==true)
			winner = black;
		else
			winner = white;
		return true;
	}
	for(int i=0;i<32;i++)
		if(desk.getFigure(i)->getType()!=king && desk.getFigure(i)->isEat() == true)
			return false;
		else
		{
			winner = twoWinner;
			return true;
		}

	return false;
}

void Player::printWinner()
{
	if(winner==white)
		cout<<"white Player win"<<endl;
	if(winner==black)
		cout<<"black Player win"<<endl;
	if(winner == twoWinner)
		cout<<"black Player win"<<endl;
	newGame();
	return;
}

void Player::newGame()
{
	winner = nobody;
	desk.createNewDesk();
	return;
}

void Player::cancelTurn(int coordinateX, int coordinateY, int number)
{
	if(number==-1)
		return;
	desk.getFigure(number)->setX(coordinateX);
	desk.getFigure(number)->setY(coordinateY);
	desk.getFigure(number)->eatFigure(false);
	return;
}