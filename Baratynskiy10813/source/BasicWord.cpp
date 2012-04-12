#include "BasicWord.h"
BasicWord::BasicWord()
{
	for (int i=0;i<6;i++)
		mistakes[i] = ' ';
};
string BasicWord::getWord()
{
	return word;
};
