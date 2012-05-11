#include <iostream>
using namespace std;
#include"field.h"

void Field:: transformKing()//����������� ����� � �����
{ 
	for(int j=0;j<size;j++)
	{
	if(gameField[size-1][j]==whiteShashka)//���� ����� ����� ����������� �� ��������� �������
		gameField[size-1][j]=whiteKing;//����������� �� � ����� �����
	if(gameField[0][j]==blackShashka)//���� ������ ����� ����������� �� ������ �������
		gameField[0][j]=blackKing;//����������� �� � ������ �����
	}
}
Field::~Field()
{	
}
Field::Field()
{
}
void Field::fieldMake()//���������� ����
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
int Field::endOfGame()//�������� ��������� ����
{
	int k=0;
	int m=0;
	for(int i=0;i<size;i++)
	{
		for (int j=0; j<size; j++)
			{
				if(gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing)
					k++;//������� ����� ����� �� ��������� �����
				if(gameField[i][j]==blackShashka || gameField[i][j]==blackKing)
					m++;//������� ������ ����� �� ��������� �����
		}
	}
	if(k==0)
		return 2;//��� ����� �����,�� ���� ������� �����,�������� �������
	if(m==0)
		return 1;//��� ������ �����,�� ���� ������� �����, �������� ������
	return 0;
}