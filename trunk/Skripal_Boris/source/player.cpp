#include "player.h"

Player::Player()
{
	winner = nobody;
	canRokirovkaWhite = true;
	canRokirovkaBlack = true;
	whitePlayerTurn = true;
}

bool Player::canTurn(int startX,int startY,int finishX,int finishY)
{
}

bool Player::makeTurn(int startX,int startY,int finishX,int finishY)
{
	if(canTurn(startX,startY,finishX,finishY)==false)
		return false;
	board.desk[finishX][finishY].type=board.desk[startX][startY].type;
	board.desk[finishX][finishY].whiteFigure=board.desk[startX][startY].whiteFigure;
	board.desk[finishX][finishY].steps=board.desk[startX][startY].steps;
	board.desk[startX][startY].type=emptyCell;
	board.desk[finishX][finishY].steps++;
	board.desk[startX][startY].steps=0;
	checkWinner();
	if(whitePlayerTurn==true)
		whitePlayerTurn=false;
	else
		whitePlayerTurn=true;
	return true;
}