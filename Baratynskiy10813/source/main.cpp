#include <iostream>
#include "Man.h"
#include "Game.h"
#include "Test.h"
#include <locale.h>

using namespace std;

void main()
{
	setlocale( LC_ALL,"Russian" );
	Game *game=new Game;
	Test *test=new Test;
	if (test->fullTest())
		game->play();
	else
		cout<<"Тесты не были успешно пройдены! Приложение будет закрыто!"<<endl;
}