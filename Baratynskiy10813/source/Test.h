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
	bool test1();
	bool test2();
	bool test3();
	bool test4();
	bool test5();
	bool test6();
public:
	Test();
	~Test();
	bool fullTest();
};
#endif