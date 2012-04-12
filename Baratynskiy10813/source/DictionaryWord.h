#ifndef DICTIONARYWORD_H
#define DICTIONARYWORD_H
#include <iostream>
#include <string>
#include "BasicWord.h"
using namespace std;
class DictionaryWord : public BasicWord
{
public:
	DictionaryWord();
	void setWord(string dword);
};
#endif