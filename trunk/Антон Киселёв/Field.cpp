#include "Field.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
Field::Field(void)
{
	GameField = new int *[ 9 ];
	for (int i = 0; i < 9; i++)
		GameField[ i ] = new int [ 9 ];
	InitField();
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
//Определение количества пропусков
int Field::CountZero()
{
	int count = 0;
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			if (GameField[ ixRow ][ ixCol ] == 0)
				count++;
		}
	}
	return count;
}
//Заполнение пропусками
void Field::Fill_Zero(int NumberOfZero)
{
	Fill_Zero_Square(0, 0, NumberOfZero);
	Fill_Zero_Square(0, 3, NumberOfZero);
	Fill_Zero_Square(0, 6, NumberOfZero);
	Fill_Zero_Square(3, 0, NumberOfZero);
	Fill_Zero_Square(3, 3, NumberOfZero);
	Fill_Zero_Square(3, 6, NumberOfZero);
	Fill_Zero_Square(6, 0, NumberOfZero);
	Fill_Zero_Square(6, 3, NumberOfZero);
	Fill_Zero_Square(6, 6, NumberOfZero);
}
//Заполнение каждого отдельного квадрата 3 на 3 пропусками
void Field::Fill_Zero_Square(int a, int b, int NumberOfZero)
{
	for (int i = 0; i < NumberOfZero; i++)
	{
		int ixRow = rand()%3+a;
		int ixCol = rand()%3+b;
		GameField[ ixRow ][ ixCol ] = 0;
	}
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
//Определение победы игрока
int Field::Define_Victory(char name[])
{
	int count = 0;
	FieldVictory = new int* [ 9 ];
	for (int i = 0; i < 9; i++)
		FieldVictory[ i ] = new int [ 9 ];
	ifstream in;
	in.open(name);
	int ixRow = 0;
	int ixCol = 0;
	while (!in.eof())
	{
		if (ixCol == 9)
		{
			ixRow++;
			ixCol = 0;
		}
		in >> FieldVictory[ ixRow ][ ixCol ];
		ixCol++;
	}
	for (ixRow = 0; ixRow < 9; ixRow++)
	{
		for (ixCol = 0; ixCol < 9; ixCol++)
		{
			if (GameField[ ixRow ][ ixCol ] != FieldVictory[ ixRow ][ ixCol ])
			{
				cout << "Есть ошибка в клетке с координатами: " << ixRow+1 << ixCol+1 << "\n";
				count++;
			}
		}
	}
	if (count == 0)
	{
		cout << "Вы выиграли!\n";
		return 0;
	}
	else
	{
		return count;
	}
}
Field::~Field(void)
{
}
