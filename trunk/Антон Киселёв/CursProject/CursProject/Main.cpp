#include <iostream>
#include <fstream>
#include <locale.h>
#include "Field.h"
#include "Row.h"
#include "Column.h"
#include "Square3x3.h"
#include "Cell.h"
#include "GameLevel.h"
using namespace std;
void main(void)
{
	setlocale(LC_ALL, "Russian");
	int G;
	int num;
	GameLevel LEVEL;
	cout << "�������� ������� ���������:\n";
	cout << "1. 9 �������� ���������\n";
	cout << "2. 20 �������� ���������\n";
	cout << "3. 60 �������� ���������\n";
	cin >> num;
	cout << "�������\n";

	if (num == 1)
	{G = LEVEL.Level(num);
	Field Game;
	Game.Fill_Zero(G);
	Game.ShowMas();}

	else if (num == 2)
	{G = LEVEL.Level(num);
	Field Game;
	Game.Fill_Zero(G);
	Game.ShowMas();}

	else if (num == 3)
	{G = LEVEL.Level(num);
	Field Game;
	Game.Fill_Zero(G);
	Game.ShowMas();}
}