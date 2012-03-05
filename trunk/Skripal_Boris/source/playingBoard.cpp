#include "playingBoard.h"

#include <iostream>

using namespace std;

Desk::Desk()
{
	clearBoard();
}

void Desk::clearBoard()
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
		desk[0][0].whiteFigure=desk[0][7].whiteFigure=true;
		desk[0][0].type=desk[0][7].type=rook;
		desk[7][0].whiteFigure=desk[7][7].whiteFigure=false;
		desk[7][0].type=desk[7][7].type=rook;
//Расстановка коней
		desk[0][1].whiteFigure=desk[0][6].whiteFigure=true;
		desk[0][1].type=desk[0][6].type=horse;
		desk[7][1].whiteFigure=desk[7][6].whiteFigure=false;
		desk[7][1].type=desk[7][6].type=horse;
//Расстановка слонов
		desk[0][2].whiteFigure=desk[0][5].whiteFigure=true;
		desk[0][2].type=desk[0][5].type=elephant;
		desk[7][2].whiteFigure=desk[7][5].whiteFigure=false;
		desk[7][2].type=desk[7][5].type=elephant;
//Расстановка ферзей
		desk[0][4].whiteFigure=true;
		desk[7][4].whiteFigure=false;
		desk[0][4].type=desk[7][4].type=queen;
//Расстановка королей
		desk[0][3].whiteFigure=true;
		desk[7][3].whiteFigure=false;
		desk[0][3].type=desk[7][3].type=king;
//Расстановка пешек
		for(int i=0;i<8;i++)
		{
			desk[1][i].whiteFigure=true;
			desk[6][i].whiteFigure=false;
			desk[1][i].type=desk[6][i].type=pawn;
		}
	return;
}

void Desk::printBoard()
{
	for(int i=0;i<8;i++)
	{
		for(int k=0;k<8;k++)
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
		}
		cout<<endl<<endl;
	}
	return;
}