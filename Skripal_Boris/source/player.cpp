#include "player.h"

#include <fstream>

Player::Player()
{
    desk = new Desk;
	winner = nobody;
	whitePlayerTurnNow = true;
    whitePlayerWins=0;
    blackPlayerWins=0;

}



bool Player::checkWinner()
{
    bool whitePlayerLastWinner;
    if(desk->checkMat(whitePlayerTurnNow)==true)
	{
        if(whitePlayerTurnNow==false)
        {
			winner = black;
            whitePlayerLastWinner = true;
            plusWinner(whitePlayerLastWinner);
            printMat();
            newGame();
        }
		else
        {
			winner = white;
            whitePlayerLastWinner = false;
           plusWinner(whitePlayerLastWinner);
           printMat();
           newGame();
        }
		return true;
	}
	for(int i=0;i<32;i++)
        if(desk->getFigure(i)->getType()!=king && desk->getFigure(i)->isEat() == false)
			return false;
		else
		{
			winner = twoWinner;
            printMat();
            newGame();
			return true;
		}

	return false;
}

void Player::printWinner()
{
	if(winner==white)
    {
        //cout<<"white Player win"<<endl;
//        QMessageBox *message = new QMessageBox;
//        message->information(*this,"","White Player win!");
//        delete message;
    }
	if(winner==black)
        //cout<<"black Player win"<<endl;
    {
//        QMessageBox *message = new QMessageBox;
//        message->information(*this,"","Black Player win!");
//        delete message;
    }
	if(winner == twoWinner)
    {
//        QMessageBox *message = new QMessageBox;
//        message->information(*this,"","Two Player win!");
//        delete message;
    }
	newGame();
	return;
}

void Player::newGame()
{
    whitePlayerTurnNow = true;
	winner = nobody;
    desk->createNewDesk();
	return;
}

bool Player::getWhitePlayerTurnNow()
{
    return whitePlayerTurnNow;
}

void Player::insertWhitePlayerTurnNow()
{
    whitePlayerTurnNow =! whitePlayerTurnNow;
}


void Player::makePlayerTurn(int startX, int startY, int finishX, int finishY)
{


        bool isTurnTrue = desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurnNow);

        if(isTurnTrue == true)
        {
            insertWhitePlayerTurnNow();
        }
        else
            printFalseTurn();
         checkWinner();

       if(desk->checkShah(whitePlayerTurnNow)==true)
           {
               printShah();
           }
}

int Player::getBlackPlayerWins()
{
    return blackPlayerWins;
}

int Player::getWhitePlayerWins()
{
    return whitePlayerWins;
}

void Player::plusWinner(bool whitePlayer)
{
    if(whitePlayer)
        whitePlayerWins++;
    else
        blackPlayerWins++;
}

Winner Player::getWinner()
{
    return winner;
}
