#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Man.h"
#include "Word.h"
#include "Library.h"

using namespace std;

class Game
{
	Word word;
	Man man;
	Library lib;
	int chooseHowToPlay();
	void putLetter();
	bool checkLetter();
	bool isWon();
	bool isLose();
	void enterLetter();
	void clearScreen();
	bool playAgain();
	void reset();
public:
	int play();
};
#endif