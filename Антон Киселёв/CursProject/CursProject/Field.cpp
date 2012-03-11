#include "Field.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Row.h"
#include "Column.h"
#include "Square3x3.h"
using namespace std;
//Создание поля
Field::Field(void)
{
	srand((unsigned)time(0));
	int chislo = rand()%9+1;
	GameField = new int* [ 9 ];
	for (int i = 0; i < 9; i++)
		GameField[ i ] = new int [ 9 ];
	InitMas();
	Sudoku(chislo);
}
//Квадрат
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
//Колонка
int Field::IsVer(int ixRow, int chislo)
{
	for (int SqIxCol = 0; SqIxCol < 9; ++SqIxCol)
		if (GameField[ ixRow ][ SqIxCol ] == chislo)
			return 1;
	return 0;
}
//Строка
int Field::IsHor(int ixCol, int chislo)
{
	for (int SqIxRow = 0; SqIxRow < 9; ++SqIxRow)
		if (GameField[ SqIxRow ][ ixCol ] == chislo)
			return 1;
	return 0;
}
//Заполнение массива
void Field::InitMas()
{
	for (int ixRow = 0; ixRow < 9; ++ixRow)
		for (int ixCol = 0; ixCol < 9; ++ixCol)
			GameField[ ixRow ][ ixCol ] = -1;
}
//Формируем поле
void Field::Sudoku(int chislo)
{
	for (int ixRow = 0; ixRow < 9; ++ixRow)
	{
		for (int ixCol = 0; ixCol < 9; ++ixCol)
		{
			int count = 9;
			for (int var = 1; var < 10; ++var)
				if (IsSq(ixRow, ixCol, var) || IsHor(ixCol, var) || IsVer(ixRow, var))
					--count;
			if (!count)
			{
				InitMas();
				Sudoku(chislo);
				return;
			}
			while (IsSq(ixRow, ixCol, chislo) || IsHor(ixCol, chislo) || IsVer(ixRow, chislo))
				chislo = rand()%9+1;
			GameField[ ixRow ][ ixCol ] = chislo;
		}
	}
}
//Заполняем нулями(пропусками)
void Field::Fill_Zero(int G)
{
	int ixRow = 0;
	int ixCol = 0;
	
	int RandomRowIndex = 0;
	int RandomColIndex = 0;
	bool A = 0;
	bool B = 0;
	bool C = 0;
	int count = G;
	do
	{
		RandomRowIndex = rand()%9;
		RandomColIndex = rand()%9;
		ixRow = RandomRowIndex;
		ixCol = RandomColIndex;
		GameField[ ixRow ][ ixCol ] = 0;
		ixRow = 0;
		ixCol = 0;
		count--;
	}while (count != 0);
}
//Выводим поле
void Field::ShowMas()
{
	for (int ixRow = 0; ixRow < 9; ++ixRow)
	{
		for (int ixCol = 0; ixCol < 9; ++ixCol)
			printf("%3d", GameField[ ixRow ][ ixCol ]);
		printf("\n\n");
	}
}

Field::~Field(void)
{
}