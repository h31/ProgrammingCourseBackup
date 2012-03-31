#include "BasicWord.h"
BasicWord::BasicWord()
{
	for (int i=0;i<6;i++)
		mistakes[i] = ' ';
};
void BasicWord::makeMask()
{
	mask=word;
	for (int i=0;i<word.length();i++)
		mask[i] = '*';
};
void BasicWord::putMistake(int curMisses)
{
	mistakes[curMisses]=letter;
};
bool BasicWord:: checkLetter()
{
	enterLetter();
	bool curStatus = false;
	for (int i=0;i<word.length();i++)
		if (word[i]==letter)
			curStatus = true;
	return curStatus;
};
void BasicWord:: enterLetter()
{
	bool status = false;
	cout<<"Введите букву: ";
	cin>>letter;
	for (int i=0;i<6;i++)
		if (letter==mistakes[i])
			status = true;
	if (status == true)
	{
		cout<<"Вы уже вводили данную букву!"<<endl;
		enterLetter();
	}
};
void BasicWord:: putLetter()
{
	for (int i=0;i<word.length();i++)
	{
		if (letter==word[i])
		{
			mask[i] = letter;
		}
	}
};