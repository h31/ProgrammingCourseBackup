#include <iostream>
#include "Man.h"
#include "Word.h"
#include "Game.h"
#include <locale.h>

using namespace std;

void main()
{
	setlocale( LC_ALL,"Russian" );
	Game *game=new Game;
	game->play();
}