#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Man.h"
#include "DictionaryWord.h"
#include "UserWord.h"
#include "Library.h"

using namespace std;

class Game
{
	Man *man;
	Library *lib;
	DictionaryWord *dword;
	UserWord *uword;
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