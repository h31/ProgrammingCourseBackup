#include "player.h"

#include <iostream>

using namespace std;

Player::Player()
{
	winner = nobody;
	whitePlayerTurn = true;
}

bool Player::canTurn(const int startX,const int startY,const int finishX,const int finishY)
{
	if(startX<0 || startX>7 || finishX< 0 || finishX>7)
	{
		cout<<"Uncorrectly coordinates"<<endl;
		return false;
	}
	if(startY<0 || startY>7 || finishY< 0 || finishY>7)
	{
		cout<<"Uncorrectly coordinates"<<endl;
		return false;
	}
	if(board.desk[startX][startY].type==emptyCell)
		return false;
	if(board.desk[startX][startY].whiteFigure!=whitePlayerTurn)
		return false;
	if(board.desk[finishX][finishY].whiteFigure == whitePlayerTurn && board.desk[finishX][finishY].type!=emptyCell)
		return false;
	if(board.canFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn)==true)
		return true;

	return false;
}

bool Player::makeTurn(const int startX,const int startY,const int finishX,const int finishY)
{
	if(makeÑastling(startX,startY,finishX,finishY)==true)
	{
		if(whitePlayerTurn==true)
		whitePlayerTurn=false;
	else
		whitePlayerTurn=true;
		return true;
	}
	if(canTurn(startX,startY,finishX,finishY)==false)
		return false;
	board.desk[finishX][finishY].type=board.desk[startX][startY].type;
	board.desk[finishX][finishY].whiteFigure=board.desk[startX][startY].whiteFigure;
	board.desk[finishX][finishY].steps=board.desk[startX][startY].steps;
	board.desk[startX][startY].type=emptyCell;
	board.desk[finishX][finishY].steps++;
	board.desk[startX][startY].steps=0;
	//checkWinner();
	if(whitePlayerTurn==true)
		whitePlayerTurn=false;
	else
		whitePlayerTurn=true;
	return true;
}

bool Player::haveWinner()
{
	if(winner!=nobody)
		return true;
	else
		return false;
}

bool Player::whitePlayerTurnNow()
{
	if(whitePlayerTurn==true)
		return true;
	else
		return false;
}

bool Player::makeÑastling(const int startX,const int startY,const int finishX,const int finishY)
{
	int startRookCoordinatesX, startRookCoordinatesY,finishRookCoordinatesX,finishRookCoordinatesY;
	if(board.desk[startX][startY].type==king)
		if((startY-finishY)==0&&abs(finishX-startX)==2)
			if(board.desk[startX][startY].steps==0)
			{
				cout<<"If you want make castling please enter cootdinates of rook. Else please enter coordinates of other figures"<<endl;
				cin>>startRookCoordinatesX>>startRookCoordinatesY;
				startRookCoordinatesX--;
				startRookCoordinatesY--;
				finishRookCoordinatesY=startRookCoordinatesY;
				finishRookCoordinatesX=startX-(startX-startRookCoordinatesX)/abs(startX-startRookCoordinatesX);
				if(board.desk[startRookCoordinatesX][startRookCoordinatesY].type==rook)
					if(board.desk[startRookCoordinatesX][startRookCoordinatesY].whiteFigure==whitePlayerTurn)
						if(board.desk[startRookCoordinatesX][startRookCoordinatesY].steps==0)
							if(board.canFigureTurn(startRookCoordinatesX,startRookCoordinatesY,finishRookCoordinatesX,finishRookCoordinatesY,whitePlayerTurn)==true)
							{
								board.desk[startX-2*(startX-startRookCoordinatesX)/abs(startX-startRookCoordinatesX)][startY]=board.desk[startX][startY];
								board.desk[finishRookCoordinatesX][finishRookCoordinatesY]=board.desk[startRookCoordinatesX][startRookCoordinatesY];
								board.desk[startX-2*(startX-startRookCoordinatesX)/abs(startX-startRookCoordinatesX)][startY].steps++;
								board.desk[startRookCoordinatesX][startRookCoordinatesY].steps++;
								board.desk[startRookCoordinatesX][startRookCoordinatesY].type=emptyCell;
								board.desk[startX][startY].type=emptyCell;
								cout<<"Sucsess castling"<<endl;
								return true;
							}
			}
	return false;

}