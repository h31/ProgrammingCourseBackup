#ifndef DICTIONARYWORD_H
#define DICTIONARYWORD_H
#include <iostream>
#include <string>
#include "BasicWord.h"
#include "Library.h"
using namespace std;
class DictionaryWord : public BasicWord
{
	Library lib;
public:
	DictionaryWord();
	void takeTheWord();
};
#endif