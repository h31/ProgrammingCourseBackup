#ifndef LIBRARY_H
#define LIBRARY_H
#include <fstream>
#include "DictionaryWord.h"
#include <time.h>

class Library
{
	int randNum;
	int var;
	DictionaryWord *word;
	int numberOfWords(ifstream &in);
	DictionaryWord* takeWord(ifstream &in);
public:
	Library();
	~Library();
	DictionaryWord* takeWordOfLang();
	int chooseTheme();
};
#endif