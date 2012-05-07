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

//bool Player::makeGame()
//{
//    //ofstream fout ("mat.txt");

//    //desk.printPlayingBoard();
//	while(winner == nobody)
//	{
//        if(desk->checkShah(whitePlayerTurnNow)==true)
//		{
//			checkWinner();
//            //cout<<"Shah"<<endl;
//           // QMessageBox message::information(*MainWindow,"","Shah!");
//		}
//		if(whitePlayerTurnNow==true)
//			cout<<"White player turn now"<<endl;
//		else
//			cout<<"Black player turn now"<<endl;

//        //cin>>startX>>startY>>finishX>>finishY;
//        //fout<<startX<<" "<<startY<<" "<<finishX<<" "<<finishY<<endl;
//       bool isTurnTrue = desk->makeFigureTurn(cord.startX,cord.startY,cord.finishX,cord.finishY,whitePlayerTurnNow);

//		if(isTurnTrue == true)
//		{
//			whitePlayerTurnNow=!whitePlayerTurnNow;
//			cout<<"Turn is sucsess"<<endl;
//            isTurnTrue = false;
//		}
//		else
//		{
//            //cout<<"turn is false"<<endl;
////            QMessageBox *message = new QMessageBox;
////            message->information(*this,"","Turn is false!");
////            delete message;

//		}
//        //desk.printPlayingBoard();
//	}
//	return true;
//}

bool Player::checkWinner()
{
    if(desk->checkMat(whitePlayerTurnNow)==true)
	{
		if(whitePlayerTurnNow==true)
        {
			winner = black;
            blackPlayerWins++;
        }
		else
        {
			winner = white;
            whitePlayerWins++;
        }
		return true;
	}
	for(int i=0;i<32;i++)
        if(desk->getFigure(i)->getType()!=king && desk->getFigure(i)->isEat() == true)
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
    if(desk->checkShah(whitePlayerTurnNow)==true)
        {
            checkWinner();
              //cout<<"Shah"<<endl;
              // QMessageBox message::information(*MainWindow,"","Shah!");
        }
   //		if(whitePlayerTurnNow==true)
   //			cout<<"White player turn now"<<endl;
   //		else
   //			cout<<"Black player turn now"<<endl;

   //        //cin>>startX>>startY>>finishX>>finishY;
   //        //fout<<startX<<" "<<startY<<" "<<finishX<<" "<<finishY<<endl;
        bool isTurnTrue = desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurnNow);

        if(isTurnTrue == true)
        {
            insertWhitePlayerTurnNow();
            //cout<<"Turn is sucsess"<<endl;
           // isTurnTrue = false;
        }
//   		else
//   		{
               //cout<<"turn is false"<<endl;
   ////            QMessageBox *message = new QMessageBox;
   ////            message->information(*this,"","Turn is false!");
   ////            delete message;
}

int Player::getBlackPlayerWins()
{
    return blackPlayerWins;
}

int Player::getWhitePlayerWins()
{
    return whitePlayerWins;
}
