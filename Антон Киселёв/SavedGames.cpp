#include "SavedGames.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Field.h"
using namespace std;
SavedGames::SavedGames()
{
}
//Сохранение сгенерированного поля
void SavedGames::SaveReadyField(Field* GameField, char name[])
{
	ofstream out("CurrentGameField.txt");
	if (!out)
	{
		cout << "Файл не открылся!\n";
		return;
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
			out << GameField->FieldVictory[ ixRow ][ ixCol ] << " ";
		out << "\n";
	}
}
//Запрос на сохранения игры
bool SavedGames::SaveRequest(int choice, Field* GameField)
{
	if (choice == 1)
	{
		char name[ 20 ];
		cout << "Введите имя игры: \n";
		cin >> name;
		SaveNameLastGame(name);
		RecordData(name, GameField);
		return true;
	}
	else if (choice == 2)
	{
		return false;
	}
}
//Сохранение имени последней игры
void SavedGames::SaveNameLastGame(char name[])
{
	ofstream out("LastSave.txt");
	if (!out)
	{
		cout << "Файл не открывается!\n";
	}
	out << name;
}
//Запись текущей игры
void SavedGames::RecordData(char name[], Field* GameField)
{
	ofstream out(name);
	if (!out)
		cout << "\n";
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			out << GameField->GameField[ ixRow ][ ixCol ];
			out << " ";
		}
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			out << GameField->FieldVictory[ ixRow ][ ixCol ];
			out << " ";
		}
	}
}
//Запрос на загрузку игры
void SavedGames::LoadRequest(int choice, Field* GameField)
{
	if (choice == 1)
	{
		ifstream in("LastSave.txt");
		if (!in)
		{
			cout << "Файл не открывается!\n";
			return;
		}
		char name[ 20 ];
		in >> name;
		LoadGame(name, GameField);
	}
	else if (choice == 2)
	{
		exit(0);
	}
}
//Загрузка сохранённой игры
void SavedGames::LoadGame(char name[], Field* GameField)
{
	ifstream in(name);
	if (!in)
	{
		cout << "Файл не открылся!\n";
		return;
	}
	ofstream out("CurrentGameField.txt");
	if (!out)
	{
		cout << "Файл не открылся!\n";
		return;
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			in >> GameField->GameField[ ixRow ][ ixCol ];
		}
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			in >> GameField->FieldVictory[ ixRow ][ ixCol ];
			out << GameField->FieldVictory[ ixRow ][ixCol];
			out << " ";
		}
		out << "\n";
	}
}
SavedGames::~SavedGames(void)
{
}
