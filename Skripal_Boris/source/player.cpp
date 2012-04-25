#include "player.h"

#include <fstream>

Player::Player()
{
	winner = nobody;
	whitePlayerTurnNow = true;

}

bool Player::makeGame()
{
	//ofstream fout ("enPassant.txt");

	int startX,startY,finishX,finishY;
	desk.printPlayingBoard();
	while(winner == nobody)
	{
		if(desk.checkShah(whitePlayerTurnNow)==true)
		{
			checkWinner();
			cout<<"Shah"<<endl;
		}
		if(whitePlayerTurnNow==true)
			cout<<"Whie player turn now"<<endl;
		else
			cout<<"Black player turn now"<<endl;

		cin>>startX>>startY>>finishX>>finishY;
		//fout<<startX<<" "<<startY<<" "<<finishX<<" "<<finishY<<endl;

		bool isTurnTrue = desk.makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurnNow);

		if(isTurnTrue == true)
		{
			whitePlayerTurnNow=!whitePlayerTurnNow;
			cout<<"Turn is sucsess"<<endl;
		}
		else
		{
			cout<<"turn is false"<<endl;
		}
		desk.printPlayingBoard();
	}
	return true;
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

