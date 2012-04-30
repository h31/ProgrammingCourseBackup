#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include "Game.h"
#include "Field.h"
#include "SavedGames.h"
using namespace std;
void main(void)
{
	setlocale(LC_ALL, "Russian");
	Game MyGame;
	MyGame.Menu();
}