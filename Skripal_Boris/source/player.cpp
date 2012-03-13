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
	if(startX<0 || startX>7 || finishX< 0 || finishX>7)
		return false;
	if(startY<0 || startY>7 || finishY< 0 || finishY>7)
		return false;

	if(board.desk[startX][startY].cellType==emptyCell)
		return false;
	if(board.desk[startX][startY].whiteFigure==true && whitePlayerTurn == false)
		return false;
	if(board.desk[startX][startY].whiteFigure==false && whitePlayerTurn == true)
		return false;
	if(board.desk[finishX][finishY].whiteFigure == true && whitePlayerTurn==true)
		return false;
	if(board.desk[finishX][finishY].whiteFigure == false && whitePlayerTurn==false)
		return false;

	if(board.desk[startX][startY].cellType==pawn)
		return board.canPawnTurn(startX,startY,finishX,finishY,whitePlayerTurn);
	if(board.desk[startX][startY].cellType==king)
		return board.canKingTurn(startX,startY,finishX,finishY);
	if(board.desk[startX][startY].cellType==rook)
		return board.canRookTurn(startX,startY,finishX,finishY);
	if(board.desk[startX][startY].cellType==queen)
		return board.canQueenTurn(startX,startY,finishX,finishY);
	if(board.desk[startX][startY].cellType==horse)
		return board.canHourseTurn(startX,startY,finishX,finishY);
	if(board.desk[startX][startY].cellType==elephant)
		return board.canElephantTurn(startX,startY,finishX,finishY);

	return false;
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