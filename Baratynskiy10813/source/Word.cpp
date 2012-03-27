#include "Word.h"
Word::Word()
{
	for (int i=0;i<6;i++)
		mistakes[i] = ' ';
};
void Word::makeMask()
{
	mask=word;
	for (int i=0;i<word.length();i++)
		mask[i] = '*';
};
void Word::putMistake(int curMisses)
{
	mistakes[curMisses]=letter;
};