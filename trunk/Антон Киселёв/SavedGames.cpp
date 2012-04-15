#include "SavedGames.h"
#include <iostream>
#include <fstream>
#include "Field.h"
using namespace std;
SavedGames::SavedGames()
{
}
//���������� ���������������� ����
void SavedGames::SaveField(Field GameField, char name[])
{
	RecordData(name, GameField);
	SaveGame();
}
//������ �� ���������� ����
bool SavedGames::SaveRequest(Field GameField)
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
//������ ������� ����
void SavedGames::RecordData(char name[], Field GameField)
{
	for (int ixRow = 0; ixRow < 100; ixRow++)
		Name[ ixRow ] = name[ ixRow ];
	for (int ixRow = 0; ixRow < 9; ixRow++)
		for (int ixCol = 0; ixCol < 9; ixCol++)
			Array[ ixRow ][ ixCol ] = GameField.GameField[ ixRow ][ ixCol ];
}
//���������� ����
void SavedGames::SaveGame()
{
	ofstream out;
	out.open(Name);
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
			out << Array[ ixRow ][ ixCol ] << " ";
		out << "\n";
	}
}
//������ �� �������� ����
void SavedGames::LoadRequest(Field GameField)
{
	char name[ 20 ];
	cout << "�������� ���� �� ������, ������� ��� ����: \n";
	cin >> name;
	LoadGame(name, GameField);
}
//�������� ���������� ����
void SavedGames::LoadGame(char name[], Field GameField)
{
	int ixRow = 0;
	int ixCol = 0;
	ifstream in(name);
	while (!in.eof())
	{
		if (ixCol == 9)
		{
			ixRow++;
			ixCol = 0;
		}
		in >> Array[ ixRow ][ ixCol ];
		ixCol++;
	}
	for (ixRow = 0; ixRow < 9; ixRow++)
		for (ixCol = 0; ixCol < 9; ixCol++)
			GameField.GameField[ ixRow ][ ixCol ] = Array[ ixRow ][ ixCol ];
}
SavedGames::~SavedGames(void)
{
}
