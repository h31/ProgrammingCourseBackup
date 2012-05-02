#include "Test.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
Test::Test(void)
{
	srand((unsigned)time(0));
	int chislo = rand()%9+1;
	GameField = new Field(chislo);
	SavedGame = new SavedGames();
	Sudoku = new Game();
}
Test::~Test(void)
{
	delete[] GameField;
	delete[] SavedGame;
	delete[] Sudoku;
}
/*Вспомогательные функции тестирования*/
//Запись в файл
void Test::RecordFirstFile()
{
	int ixRow = 0;
	int ixCol = 0;
	ofstream out("TestField.txt");
	if (!out)
	{
		cout << "Файл не открывается!\n";
	}
	for (ixRow = 0; ixRow < 9; ixRow++)
	{
		for (ixCol = 0; ixCol < 9; ixCol++)
		{
			out << GameField->GameField[ ixRow ][ ixCol ];
			out << " ";
		}
		out << "\n";
	}
}
//Считывание из файла
void Test::RecordSecondFile()
{
	int ixRow = 0;
	int ixCol = 0;
	ifstream in("TestField.txt");
	if (!in)
	{
		cout << "Файл не открывается!\n";
	}
	for (ixRow = 0; ixRow < 9; ixRow++)
	{
		for (ixCol = 0; ixCol < 9; ixCol++)
		{
			in >> GameField->FieldVictory[ ixRow ][ ixCol ];
		}
	}
}
/*Блок тестов класса Field*/
//Тест функции определения победы
bool Test::Test1()
{
	RecordFirstFile();
	RecordSecondFile();
	int count = GameField->CountOfMistakes();
	if (count == 0)
		return 1;
	return 0;
}
//Тест функции вставки значения
bool Test::Test2()
{
	GameField->InsertChislo(0, 0, 0);
	RecordFirstFile();
	RecordSecondFile();
	if (GameField->FieldVictory[ 0 ][ 0 ] == GameField->GameField[ 0 ][ 0 ])
		return 1;
	return 0;
}
//Тест функции возврата клетки из поля с данными координатами
bool Test::Test3()
{
	int chislo = 0;
	GameField->InsertChislo(0, 0, chislo);
	if (GameField->GetCell(0, 0) == chislo)
		return 1;
	return 0;
}
//Тест проверки значений в поле
bool Test::Test4()
{
	int count = 0;
	int Row = 0;
	int Col = 0;
	GameField->InsertChislo(0, 5, 0);
	GameField->InsertChislo(3, 4, 0);
	GameField->InsertChislo(4, 8, 0);

	GameField->ControlOfChisel(0, 5);
	Row = GameField->xx;
	Col = GameField->yy;
	if (Row == 0 && Col == 5)
		count++;
	GameField->ControlOfChisel(3, 4);
	Row = GameField->xx;
	Col = GameField->yy;
	if (Row == 3 && Col == 4)
		count++;
	GameField->ControlOfChisel(4, 8);
	Row = GameField->xx;
	Col = GameField->yy;
	if (Row == 4 && Col == 8)
		count++;
	if (count == 3)
		return 1;
	return 0;
}
//Тест на проверку взятия значения из конкретной клетки
bool Test::Test5()
{
	int chislo = GameField->GetCell(0, 0);
	if (chislo == GameField->GameField[ 0 ][ 0 ])
		return 1;
	return 0;
}
//Проверка функции победы в игре на истинность
bool Test::Test6()
{
	RecordFirstFile();
	RecordSecondFile();
	if (GameField->Define_Victory() == 1)
		return 1;
	return 0;
}
//Проверка функции победы в игре на ложность
bool Test::Test7()
{
	RecordFirstFile();
	GameField->InsertChislo(0, 0, 9);
	RecordSecondFile();
	if (GameField->Define_Victory() == 0)
		return 1;
	return 0;
}

/*Блок тестов класса SavedGames*/
//Проверка сохранения данных в файле
bool Test::Test8()
{
	int Array1[ 9 ][ 9 ];
	int Array2[ 9 ][ 9 ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			Array1[ ixRow ][ ixCol ] = 1;
			Array2[ ixRow ][ ixCol ] = 2;
		}
	}
	int count1 = 0;
	int count2 = 0;
	GameField = new Field(1);
	GameField->Fill_Zero(1);
	SavedGame->RecordData("TestField.txt", GameField);
	ifstream in("TestField.txt");
	if (!in)
	{
		cout << "Файл не открывается!\n";
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			in >> Array1[ ixRow ][ ixCol ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			in >> Array2[ ixRow ][ ixCol ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			if (GameField->GameField[ ixRow ][ ixCol ] != Array1[ ixRow ][ ixCol ])
				count1++;
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			if (GameField->FieldVictory[ ixRow ][ ixCol ] != Array2[ ixRow ][ ixCol ])
				count2++;
	if (count1 == 0 && count2 == 0)
		return 1;
	return 0;
}
//Проверка на загрузку массива из файла
bool Test::Test9()
{
	SavedGame->LoadGame("game.txt", GameField);
	int Array1[ 9 ][ 9 ];
	int Array2[ 9 ][ 9 ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			Array1[ ixRow ][ ixCol ] = 1;
			Array2[ ixRow ][ ixCol ] = 2;
		}
	}
	ifstream in("game.txt");
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			in >> Array1[ ixRow ][ ixCol ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			in >> Array2[ ixRow ][ ixCol ];
	int count1 = 0;
	int count2 = 0;
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			if (GameField->FieldVictory[ ixRow ][ ixCol ] != Array2[ ixRow ][ ixCol ])
				count1++;
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			if (GameField->GameField[ ixRow ][ ixCol ] != Array1[ ixRow ][ ixCol ])
				count2++;
	if (count1 == 0 && count2 == 0)
		return 1;
	return 0;
}
//Проверка записи готового сгенерированного поля
bool Test::Test10()
{
	int count = 0;
	GameField = new Field(1);
	SavedGame->SaveReadyField(GameField, "CurrentGameField.txt");
	int Array[ 9 ][ 9 ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			Array[ ixRow ][ ixCol ] = 1;
		}
	}
	ifstream in("CurrentGameField.txt");
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			in >> Array[ ixRow ][ ixCol ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			if (GameField->GameField[ ixRow ][ ixCol ] != Array[ ixRow ][ ixCol ])
				count++;
	if (count == 0)
		return 1;
	return 0;
}
//Итоговый тест
bool Test::FullTest()
{
	if (Test1() == 1 && Test2() == 1 && Test3() == 1 && Test4() == 1 && Test5() == 1 && Test6() == 1 && Test7() == 1 && Test8() == 1 && Test9() == 1 && Test10() == 1)
		return 1;
	return 0;
}