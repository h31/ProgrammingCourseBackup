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
//Игровое меню
void Game::Menu()
{
	cout << "Игровое меню: \n";
	cout << "1. Играть\n";
	cout << "2. Продолжить\n";
	cout << "3. Выйти\n";
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
//Выбор уровня сложности
int Game::GameLevel()
{
	int NumberOfZero = 0;
	int choice = 0;
	cout << "Выберите уровень сложности: \n";
	cout << "1. Легкий уровень\n";
	cout << "2. Средний уровень\n";
	cout << "3. Тяжёлый уровень\n";
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
//Начало игры
void Game::StartGame()
{
	int CountZero = GameLevel();
	GameField->Fill_Zero(CountZero);
	OutOfField();
}
//Игровой ход
void Game::GameStep()
{
	cout << "Введите координаты и значение, которое вы хотите вставить: \n";
	int ixRow = 0;
	int ixCol = 0;
	int chislo = 0;
	cin >> ixRow >> ixCol >> chislo;
	ixRow--;
	ixCol--;
	GameField->InsertChislo(ixRow, ixCol, chislo);
	OutOfField();
}
//Проверка поля на ошибки
void Game::ControlField()
{
	cout << "Вы желаете проверить текущую игру? \n";
	cout << "1. Да\n";
	cout << "2. Нет\n";
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ifstream in("CurrentGameField.txt");
		if(!in.fail())
		{
			cout << "Файл не открылся!\n";
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
		cout << "Есть ошибка в клетках с координатами: " << GameField->ControlOfChisel() << "\n";
	}
}
//Игра
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
//Конец игры
void Game::EndGame()
{
	ifstream in("CurrentGameField.txt");
	if(!in.fail())
	{
		cout << "Файл не открылся!\n";
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
		cout << "Вы выиграли!\n";
	else if (victory == 0)
	{
		cout << "Есть ошибка в клетках с координатами: " << GameField->ControlOfChisel() << "\n";
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
//Вывод поля
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