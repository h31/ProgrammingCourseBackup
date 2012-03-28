#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Man.h"
#include "BasicWord.h"
#include "DictionaryWord.h"
#include "UserWord.h"
#include "Library.h"

using namespace std;

class Game
{
	BasicWord *bword;
	Man *man;
	DictionaryWord dword;
	UserWord uword;
	int chooseHowToPlay();
	bool isWon();
	bool isLose();
	bool playAgain();
	void reset();
	~Game();
public:
	Game();
	int play();
};
#endif