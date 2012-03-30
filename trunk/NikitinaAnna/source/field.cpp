#include <iostream>
using namespace std;
#include"field.h"

void Field:: transformKing()
{ 
	for(int j=0;j<8;j++)
	{
	if(gameField[7][j]==whiteShashka)
		gameField[7][j]=whiteKing;
	if(gameField[0][j]==blackShashka)
		gameField[0][j]=blackKing;
	}
}
void Field::permutation(int Px,int  Py,int  x, int y)
{
	gameField[Px][Py]=gameField[x][y];
	gameField[x][y]=empty;

}
void Field::print()
{
		for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<gameField[i][j];
		cout<<endl;
	}
		cout<<endl;
}
Field::Field()
 {	
	for (int j=0; j<8; j=j+2)
		{
			gameField[0][j]=empty;
			gameField[1][j]=whiteShashka;
			gameField[2][j]=empty;
			gameField[5][j]=blackShashka;
			gameField[6][j]=empty;
			gameField[7][j]=blackShashka;
		}
		for (int j=1; j<8; j=j+2)
		{
			gameField[0][j]=whiteShashka;
			gameField[1][j]=empty;
			gameField[2][j]=whiteShashka;
			gameField[5][j]=empty;
			gameField[6][j]=blackShashka;
			gameField[7][j]=empty;
		}
		for(int j=0;j<8;j++)
			{
				gameField[3][j]=empty;
				gameField[4][j]=empty;
			}
}
Field::~Field()
{
	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++)
			gameField[i][j] = empty;
}

