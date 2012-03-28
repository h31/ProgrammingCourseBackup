#ifndef LIBRARY_H
#define LIBRARY_H
#include <fstream>
#include "Man.h"
#include "BasicWord.h"
#include <time.h>

class Library
{
	int randNum;
	int var;
	BasicWord word;
	int numberOfWords(ifstream &in);
	BasicWord takeWord(ifstream &in);
public:
	BasicWord takeWordOfLang();
	int chooseTheme();
};

#endif