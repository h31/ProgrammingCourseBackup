#include "playingBoard.h"

#include <iostream>

using namespace std;

Desk::Desk()
{
	desk = new Figure* [8];
	for(int i=0;i<8;i++)
		desk[i]=new Figure [8];

	createNewPlayingBoard();
}

Desk::~Desk()
{
	for(int i=0;i<8;i++)
		delete desk[i];
	delete desk;
}

void Desk::createNewPlayingBoard()
{
	for(int i=0;i<8;i+=2)
		for(int k=0;k<8;k+=2)
		{
			desk[i][k].type=emptyCell;
			desk[i][k].cellType=whiteCell;
			desk[i][k+1].type=emptyCell;
			desk[i][k+1].cellType=blackCell;
		}
	for(int i=1;i<8;i+=2)
		for(int k=1;k<8;k+=2)
		{
			desk[i][k].type=emptyCell;
			desk[i][k].cellType=whiteCell;
			desk[i][k-1].type=emptyCell;
			desk[i][k-1].cellType=blackCell;
		}
//Расстановка ладей
		desk[0][0].whiteFigure=desk[7][0].whiteFigure=true;
		desk[0][0].type=desk[7][0].type=rook;
		desk[0][7].whiteFigure=desk[7][7].whiteFigure=false;
		desk[0][7].type=desk[7][7].type=rook;
//Расстановка коней
		desk[1][0].whiteFigure=desk[6][0].whiteFigure=true;
		desk[1][0].type=desk[6][0].type=horse;
		desk[1][7].whiteFigure=desk[6][7].whiteFigure=false;
		desk[1][7].type=desk[6][7].type=horse;
//Расстановка слонов
		desk[2][0].whiteFigure=desk[5][0].whiteFigure=true;
		desk[2][0].type=desk[5][0].type=elephant;
		desk[2][7].whiteFigure=desk[5][7].whiteFigure=false;
		desk[2][7].type=desk[5][7].type=elephant;
//Расстановка ферзей
		desk[4][0].whiteFigure=true;
		desk[4][7].whiteFigure=false;
		desk[4][0].type=desk[4][7].type=queen;
//Расстановка королей
		desk[3][0].whiteFigure=true;
		desk[3][7].whiteFigure=false;
		desk[3][0].type=desk[3][7].type=king;
//Расстановка пешек
		for(int i=0;i<8;i++)
		{
			desk[i][1].whiteFigure=true;
			desk[i][6].whiteFigure=false;
			desk[i][1].type=desk[i][6].type=pawn;
		}
	return;
}

void Desk::printBoard()
{
	cout<<"        White Player"<<endl;
	cout<<"    1  2  3  4  5  6  7  8"<<endl;
	cout<<" ___________________________"<<endl;
	for(int k=0;k<8;k++)
	{
		cout<<k+1<<"|";
		for(int i=0;i<8;i++)
		{
			if(desk[i][k].type==emptyCell && desk[i][k].cellType==blackCell)
				cout<<" * ";
			if(desk[i][k].type==emptyCell && desk[i][k].cellType==whiteCell)
				cout<<" @ ";
			if(desk[i][k].type==elephant && desk[i][k].whiteFigure==true)
				cout<<" wE";
			if(desk[i][k].type==elephant && desk[i][k].whiteFigure==false)
				cout<<" bE";
			if(desk[i][k].type==horse && desk[i][k].whiteFigure==true)
				cout<<" wH";
			if(desk[i][k].type==horse && desk[i][k].whiteFigure==false)
				cout<<" bH";
			if(desk[i][k].type==king && desk[i][k].whiteFigure==true)
				cout<<" wK";
			if(desk[i][k].type==king && desk[i][k].whiteFigure==false)
				cout<<" bK";
			if(desk[i][k].type==pawn && desk[i][k].whiteFigure==true)
				cout<<" wP";
			if(desk[i][k].type==pawn && desk[i][k].whiteFigure==false)
				cout<<" bP";
			if(desk[i][k].type==queen && desk[i][k].whiteFigure==true)
				cout<<" wQ";
			if(desk[i][k].type==queen && desk[i][k].whiteFigure==false)
				cout<<" bQ";
			if(desk[i][k].type==rook && desk[i][k].whiteFigure==true)
				cout<<" wR";
			if(desk[i][k].type==rook && desk[i][k].whiteFigure==false)
				cout<<" bR";
			//cout<<"["<<i<<"]["<<k<<"] ";
		}
		cout<<" |"<<k+1<<endl<<endl;
	}
	cout<<" ___________________________"<<endl;
	cout<<"    1  2  3  4  5  6  7  8"<<endl<<endl;
	cout<<"       Black Player"<<endl;
	return;
}



bool Desk::canFigureTurn(const int startX, const int startY, const int finishX, const int finishY, const bool whitePlayerTurn)
{
	if(desk[startX][startY].type==pawn)
		return desk[startX][startY].canPawnTurn(desk,startX,startY,finishX,finishY,whitePlayerTurn);
	if(desk[startX][startY].type==king)
		return desk[startX][startY].canKingTurn(desk,startX,startY,finishX,finishY);
	if(desk[startX][startY].type==rook)
		return desk[startX][startY].canRookTurn(desk,startX,startY,finishX,finishY);
	if(desk[startX][startY].type==queen)
		return desk[startX][startY].canQueenTurn(desk,startX,startY,finishX,finishY);
	if(desk[startX][startY].type==horse)
		return desk[startX][startY].canHourseTurn(desk,startX,startY,finishX,finishY);
	if(desk[startX][startY].type==elephant)
		return desk[startX][startY].canElephantTurn(desk,startX,startY,finishX,finishY);
}

void Desk::putFigure(Type typeFigure, const bool white, int x, int y)
{
	while(x>7||x<0||y>7||y<0)
	{
		cout<<"write correct coordinat"<<endl;
		cin>>x>>y;
	}
	desk[x][y].whiteFigure=white;
	desk[x][y].type=typeFigure;
	desk[x][y].steps=0;
}