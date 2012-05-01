#ifndef TEST_H
#define TEST_H
#include "DictionaryWord.h"
#include "UserWord.h"
#include "Game.h"
#include <fstream>
#include <iostream>

using namespace std;

class Test
{
	DictionaryWord *word;
	UserWord *uword;
	Game *game;
	Man *man;
	DictionaryWord* takeTheThirdWord();
	bool checkTheWord();
	bool checkLetter();
	bool testCheckLetterMethod();
	bool checkPutLetter();
	bool checkIsWon();
	bool checkIsLose();
public:
	Test();
	~Test();
	bool fullTest();
};
#endif