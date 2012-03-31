#ifndef BASICWORD_H
#define BASICWORD_H
#include <iostream>
#include <string>
using namespace std;
class BasicWord
{
public:
	friend class Game;
	friend class UserWord;
	friend class DictionaryWord;
	friend class Library;
private:
	BasicWord();
	void enterLetter();
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