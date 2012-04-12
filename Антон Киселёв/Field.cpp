#include "Field.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
Field::Field(void)
{
	srand((unsigned)time(0));
	int chislo = rand()%9+1;
	GameField = new int *[ 9 ];
	for (int i = 0; i < 9; i++)
		GameField[ i ] = new int [ 9 ];
	InitField();
	Generation(chislo);
	Fill_Zero();
}
//Заполнение массива готовым образцом
void Field::InitField()
{
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			GameField[ ixRow ][ ixCol ] = -1;
}
//Генерация полного поля
void Field::Generation(int chislo)
{
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
				int count = 9;
				for (int var = 1; var < 10; ++var)
					if (IsSq(ixRow, ixCol, var) || IsHor(ixCol, var) || IsVer(ixRow, var))
						--count;
				if (!count)
				{
					InitField();
					Generation(chislo);
					return;
				}
				while (IsSq(ixRow, ixCol, chislo) || IsHor(ixCol, chislo) || IsVer(ixRow, chislo))
					chislo = rand()%9+1;
				GameField[ ixRow ][ ixCol ] = chislo;
		}
	}
}
//Заполнение пропусками
void Field::Fill_Zero()
{
	srand((unsigned)time(0));
	int count = 56;
	do
	{
		int ixRow = rand()%9+1;
		int ixCol = rand()%9+1;
		ixRow--;
		ixCol--;
		GameField[ ixRow ][ ixCol ] = 0;
		count--;
	} while(count != 0);
}
//Проверка по квадрату
int Field::IsSq(int ixRow, int ixCol, int chislo)
{
	int SqIxRow = ixRow/3;
	int SqIxCol = ixCol/3;
	for (int _b(SqIxRow*3), ddi = _b; ddi < _b+3; ++ddi)
		for (int __b(SqIxCol*3), ddj = __b; ddj < __b+3; ++ddj)
			if (GameField[ ddi ][ ddj ] == chislo)
				return 1;
	return 0;
}
//Проверка по столбцу
int Field::IsVer(int ixRow, int chislo)
{
	for (int SqIxCol = 0; SqIxCol < 9; ++SqIxCol)
		if (GameField[ ixRow ][ SqIxCol ] == chislo)
			return 1;
	return 0;
}
//Проверка по строке
int Field::IsHor(int ixCol, int chislo)
{
	for (int SqIxRow = 0; SqIxRow < 9; ++SqIxRow)
		if (GameField[ SqIxRow ][ ixCol ] == chislo)
			return 1;
	return 0;
}
//Вывод поля на экран
void Field::OutOfField()
{
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			cout << " " << GameField[ ixRow ][ ixCol ] << " ";
		}
		cout << "(" << ixRow+1 << ")\n\n";
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
		cout << "(" << ixRow+1 << ")";
	cout << "\n";
}
//Взятие клетки
int Field::GetCell(int ixRow, int ixCol)
{
	return GameField[ ixRow ][ ixCol ];
}
//Вывод клетки
void Field::OutOfCell(int ixRow, int ixCol)
{
	cout << " " << GameField[ ixRow ][ ixCol ] << " ";
}
Field::~Field(void)
{
}
