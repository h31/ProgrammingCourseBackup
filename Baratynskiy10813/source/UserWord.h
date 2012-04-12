#ifndef USERWORD_H
#define USERWORD_H
#include <iostream>
#include <string>
#include "BasicWord.h"
#include "DictionaryWord.h"
using namespace std;
class UserWord : public BasicWord
{
	void enterLetter();
public:
	UserWord();
	void makeUserWord(DictionaryWord dword);
	void putMistake(int curMisses);
	bool checkLetter(DictionaryWord dword);
	void putLetter(DictionaryWord dword);
};
#endif