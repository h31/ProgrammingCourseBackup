#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include "Test.h"
#include "Game.h"
#include "Field.h"
#include "SavedGames.h"
using namespace std;
void main(void)
{
	setlocale(LC_ALL, "Russian");
	//Game MyGame;
	//MyGame.Menu();
	bool A = 0;
	Test MyTest;
	A = MyTest.FullTest();
	if (A == 1)
	{
		cout << "Тест пройден!\n";
	}
	else
	{
		cout << "Тест провален!\n";
	}
}