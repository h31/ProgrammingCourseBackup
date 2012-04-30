#include "Game.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;
Game::Game(void)
{
	srand((unsigned)time(0));
	int chislo = rand()%9+1;
	char name[ 100 ] = "CurrentGameField.txt";
	GameField = new Field(chislo);
	SavedGame = new SavedGames();
	SavedGame->SaveField(GameField, name);
}
Game::~Game(void)
{
	delete[] GameField;
	delete[] SavedGame;
}
//������� ����
void Game::Menu()
{
	cout << "������� ����: \n";
	cout << "1. ������\n";
	cout << "2. ����������\n";
	cout << "3. �����\n";
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		StartGame();
		PlayGame();
		EndGame();
	}
	else if (choice == 2)
	{
		SavedGame->LoadRequest(GameField);
		OutOfField();
		PlayGame();
	}
	else if (choice == 3)
	{
		exit(0);
	}
}
//����� ������ ���������
int Game::GameLevel()
{
	int NumberOfZero = 0;
	int choice = 0;
	cout << "�������� ������� ���������: \n";
	cout << "1. ������ �������\n";
	cout << "2. ������� �������\n";
	cout << "3. ������ �������\n";
	cin >> choice;
	if (choice == 1)
	{
		NumberOfZero = 4;
		return NumberOfZero;
	}
	else if (choice == 2)
	{
		NumberOfZero = 5;
		return NumberOfZero;
	}
	else if (choice == 3)
	{
		NumberOfZero = 6;
		return NumberOfZero;
	}
}
//������ ����
void Game::StartGame()
{
	int CountZero = GameLevel();
	GameField->Fill_Zero(CountZero);
	OutOfField();
}
//������� ���
void Game::GameStep()
{
	cout << "������� ���������� � ��������, ������� �� ������ ��������: \n";
	int ixRow = 0;
	int ixCol = 0;
	int chislo = 0;
	cin >> ixRow >> ixCol >> chislo;
	ixRow--;
	ixCol--;
	GameField->InsertChislo(ixRow, ixCol, chislo);
	OutOfField();
}
//�������� ���� �� ������
void Game::ControlField()
{
	cout << "�� ������� ��������� ������� ����? \n";
	cout << "1. ��\n";
	cout << "2. ���\n";
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ifstream in("CurrentGameField.txt");
		if(!in.fail())
		{
			cout << "���� �� ��������!\n";
			return;
		}
		int count = 0;
		GameField->FieldVictory = new int* [ 9 ];
		for (int i = 0; i < 9; i++)
			GameField->FieldVictory[ i ] = new int [ 9 ];
		int ixRow = 0;
		int ixCol = 0;
		while (!in.eof())
		{
			if (ixCol == 9)
			{
				ixRow++;
				ixCol = 0;
			}
			in >> GameField->FieldVictory[ ixRow ][ ixCol ];
			ixCol++;
		}
		cout << "���� ������ � ������� � ������������: " << GameField->ControlOfChisel() << "\n";
	}
}
//����
void Game::PlayGame()
{
	int count = GameField->CountZero();
	do
	{
		GameStep();
		SavedGame->SaveRequest(GameField);
		ControlField();
		count--;
	} while(count != 0);
}
//����� ����
void Game::EndGame()
{
	ifstream in("CurrentGameField.txt");
	if(!in.fail())
	{
		cout << "���� �� ��������!\n";
		return;
	}
	int count = 0;
	GameField->FieldVictory = new int* [ 9 ];
	for (int i = 0; i < 9; i++)
		GameField->FieldVictory[ i ] = new int [ 9 ];
	int ixRow = 0;
	int ixCol = 0;
	while (!in.eof())
	{
		if (ixCol == 9)
		{
			ixRow++;
			ixCol = 0;
		}
		in >> GameField->FieldVictory[ ixRow ][ ixCol ];
		ixCol++;
	}
	bool victory = GameField->Define_Victory();
	if (victory == 1)
		cout << "�� ��������!\n";
	else if (victory == 0)
	{
		cout << "���� ������ � ������� � ������������: " << GameField->ControlOfChisel() << "\n";
		count = GameField->CountOfMistakes();
		do
		{
			GameStep();
			SavedGame->SaveRequest(GameField);
			ControlField();
			count--;
		} while(count != 0);
	}
	OutOfField();
	SavedGame->LoadRequest(GameField);
	OutOfField();
}
//����� ����
void Game::OutOfField()
{
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			cout << " " << GameField->GameField[ ixRow ][ ixCol ] << " ";
		}
		cout << "(" << ixRow+1 << ")\n\n";
	}
	for (int ixRow = 0; ixRow < 9; ixRow++)
		cout << "(" << ixRow+1 << ")";
	cout << "\n";
}