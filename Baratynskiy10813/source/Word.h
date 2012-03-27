#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <string>
using namespace std;
class Word
{
public:
	Word();
	string word;
	string mask;
	char letter;
	char mistakes[6];
	void makeMask();
	void putMistake(int curMisses);
};
#endif