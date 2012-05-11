#include <iostream>
using namespace std;
#include"field.h"

void Field:: transformKing()//превращение шашки в дамку
{ 
	for(int j=0;j<size;j++)
	{
	if(gameField[size-1][j]==whiteShashka)//если белая шашка оказывается на последней строчке
		gameField[size-1][j]=whiteKing;//превращение ее в белую дамку
	if(gameField[0][j]==blackShashka)//если черная шашка оказывается на первой строчке
		gameField[0][j]=blackKing;//превращение ее в черную дамку
	}
}
Field::~Field()
{	
}
Field::Field()
{
}
void Field::fieldMake()//заполнение поля
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			gameField[i][j]=empty;
	}
	for(int j=0;j<size;j++)
	{
	gameField[2][j]=whiteShashka;
	gameField[5][0]=blackShashka;
	gameField[6][1]=blackShashka;
	}
	/*for(int i=0;i<size/2-1;i=i+2)
	{
		for (int j=0; j<size; j+=2)
			gameField[i][j]=empty;
		for (int j=1; j<size; j+=2)
			gameField[i][j]=whiteShashka;
	}
	for(int i=1;i<size/2-1;i+=2)
	{
		for (int j=1; j<size; j+=2)
			gameField[i][j]=empty;
		for (int j=0; j<size; j+=2)
			gameField[i][j]=whiteShashka;	
	}
	for(int i=size/2+1;i<size;i=i+2)
	{
		for (int j=0; j<size; j+=2)
			gameField[i][j]=blackShashka;
		for (int j=1; j<size; j+=2)
			gameField[i][j]=empty;
	}
	for(int i=size/2+2;i<size-1;i+=2)
	{ 
		for (int j=0; j<size; j+=2)
			gameField[i][j]=empty;
		for (int j=1; j<size; j+=2)
			gameField[i][j]=blackShashka;
	}
	for(int j=0;j<size;j++)
	{
		gameField[size/2][j]=empty;
		gameField[size/2-1][j]=empty;
	}*/

}
int Field::endOfGame()//Проверка окончания игры
{
	int k=0;
	int m=0;
	for(int i=0;i<size;i++)
	{
		for (int j=0; j<size; j++)
			{
				if(gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing)
					k++;//счетчик белых фигур на шахматной доске
				if(gameField[i][j]==blackShashka || gameField[i][j]==blackKing)
					m++;//счетчик черных фигур на шахматной доске
		}
	}
	if(k==0)
		return 2;//Нет белых шашек,то есть выиграл игрок,играющий черными
	if(m==0)
		return 1;//нет черных шашек,то есть выиграл игрок, играющий белыми
	return 0;
}