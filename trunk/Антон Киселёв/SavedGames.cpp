#include "SavedGames.h"
#include <iostream>
#include <fstream>
#include "Field.h"
using namespace std;
SavedGames::SavedGames()
{
}
//���������� ���������������� ����
void SavedGames::SaveField(Field* GameField, char name[])
{
	RecordField(name, GameField);
	SaveGameField();
}
//������ �� ���������� ����
bool SavedGames::SaveRequest(Field* GameField)
{
	int choice = 0;
	cout << "�� ������ ��������� ����? \n";
	cout << "1. ��\n";
	cout << "2. ���\n";
	cin >> choice;
	if (choice == 1)
	{
		char name[ 20 ];
		cout << "������� ��� ����: \n";
		cin >> name;
		RecordData(name, GameField);
		SaveGame();
		return true;
	}
	else if (choice == 2)
	{
		return false;
	}
}
//������ �������� ���� � ����
void SavedGames::RecordField(char name[], Field* GameField)
{
	for (int ixRow = 0; ixRow < 100; ixRow++)
		Name[ ixRow ] = name[ ixRow ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			FirstArray[ ixRow ][ ixCol ] = GameField->GameField[ ixRow ][ ixCol ];
}
//������ ������� ����
void SavedGames::RecordData(char name[], Field* GameField)
{
	int ixRow = 0;
	int ixCol = 0;
	for (int ixRow = 0; ixRow < 100; ixRow++)
		Name[ ixRow ] = name[ ixRow ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			FirstArray[ ixRow ][ ixCol ] = GameField->GameField[ ixRow ][ ixCol ];
	ifstream in("CurrentGameField.txt");
	if (!in.fail())
	{
		cout << "���� �� ��������!\n";
		return;
	}
	while (!in.eof())
	{
		if (ixCol == 9)
		{
			ixRow++;
			ixCol = 0;
		}
		in >> SecondArray[ ixRow ][ ixCol ];
		ixCol++;
	}
}
//���������� �������� ����
void SavedGames::SaveGameField()
{
	ofstream out("CurrentGameField.txt");
	if (!out.fail())
	{
		cout << "���� �� ��������!\n";
		return;
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
			out << FirstArray[ ixRow ][ ixCol ] << " ";
		out << "\n";
	}
}
//���������� ����
void SavedGames::SaveGame()
{
	ofstream out;
	if (!out.fail())
	{
		cout << "���� �� ��������!\n";
		return;
	}
	out.open(Name);
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
			out << FirstArray[ ixRow ][ ixCol ] << " ";
		out << "\n";
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
			out << SecondArray[ ixRow ][ ixCol ] << " ";
		out << "\n";
	}
}
//������ �� �������� ����
void SavedGames::LoadRequest(Field* GameField)
{
	cout << "�� ������ ��������� ���������� ����?\n";
	cout << "1. ��\n";
	cout << "2. ���\n";
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		char name[ 20 ];
		cout << "������� ��� ����: \n";
		cin >> name;
		LoadGame(name, GameField);
	}
	else if (choice == 2)
	{
		return;
	}
}
//�������� ���������� ����
void SavedGames::LoadGame(char name[], Field* GameField)
{
	int ixRow = 0;
	int ixCol = 0;
	ifstream in(name);
	if (!in.fail())
	{
		cout << "���� �� ��������!\n";
		return;
	}
	ofstream out("CurrentGameField.txt");
	if (!out.fail())
	{
		cout << "���� �� ��������!\n";
		return;
	}
	for (ixRow = 0; ixRow < 9; ixRow++)
	{
		for (ixCol = 0; ixCol < 9; ixCol++)
		{
			in >> GameField->GameField[ ixRow ][ ixCol ];
		}
	}
	for (ixRow = 0; ixRow < 9; ixRow++)
	{
		for (ixCol = 0; ixCol < 9; ixCol++)
		{
			in >> SecondArray[ ixRow ][ ixCol ];
			out << SecondArray[ ixRow ][ixCol];
			out << " ";
		}
		out << "\n";
	}
}
SavedGames::~SavedGames(void)
{
}
