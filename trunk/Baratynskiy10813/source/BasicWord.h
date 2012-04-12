#ifndef BASICWORD_H
#define BASICWORD_H
#include <iostream>
#include <string>
using namespace std;
class BasicWord
{
protected:
	char letter;
	string word;
public:
	BasicWord();
	char mistakes[6];
	string getWord();
	friend class Library;
};
#endif