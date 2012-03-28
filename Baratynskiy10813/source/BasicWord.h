#ifndef BASICWORD_H
#define BASICWORD_H
#include <iostream>
#include <string>
using namespace std;
class BasicWord
{
	void enterLetter();
public:
	BasicWord();
	string word;
	string mask;
	char letter;
	char mistakes[6];
	void makeMask();
	void putMistake(int curMisses);
	bool checkLetter();
	void putLetter();
};
#endif