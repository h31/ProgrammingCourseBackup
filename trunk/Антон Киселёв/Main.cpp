#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include "Field.h"
#include "Cell.h"
#include "SavedGames.h"
using namespace std;
void main(void)
{
	srand((unsigned)time(0));
	int chislo = rand()%9+1;
	char name[ 100 ] = "CurrentGameField.txt";

	setlocale(LC_ALL, "Russian");
	SavedGames SG;
	Field GameField = Field(chislo, name);
	GameField.OutOfField();
	//�������� ������ ���������� ������
	int ixRow = 0;
	int ixCol = 0;
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			Cell cell = Cell(GameField, ixRow, ixCol);
			cell.GetCell();
			cout << " ";
		}
		cout << "\n\n";
	}

	int level = 0;//������� ���������
	int NumberOfZero = 0;//���������� ��������� ��� ������� ������ ���������
	cout << "�������� ������� ���������: \n";
	cout << "1. ������\n";
	cout << "2. �������\n";
	cout << "3. �������\n";
	cin >> level;
	if (level == 1)
		NumberOfZero = 3;
	else if (level == 2)
		NumberOfZero = 4;
	else if (level == 3)
		NumberOfZero = 5;

	GameField.Fill_Zero(NumberOfZero);
	int num = GameField.CountZero();
	GameField.OutOfField();
	for (int i = 0; i < num; i++)
	{
		int x = 0;
		int y = 0;
		int chislo = 0;
		cout << "������� ���������� � ��������: \n";
		cin >> x >> y >> chislo;
		if (x>=1 && x<=9 && y>=1 && y<=9)
		{
			x--;
			y--;
			if (GameField.GameField[ x ][ y ] == 0)
			{
				GameField.GameField[ x ][ y ] = chislo;
				GameField.OutOfField();
				SG.SaveRequest(GameField);
			}
			else if (GameField.GameField[ x ][ y ] != 0)
			{
				cout << "������ ��� ���������!\n";
			}
		}
		else
		{
			cout << "���������� �� ��������!\n";
		}
	}

	SG.LoadRequest(GameField);
	GameField.OutOfField();
}