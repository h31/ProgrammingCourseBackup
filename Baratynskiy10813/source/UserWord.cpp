#include "UserWord.h"
UserWord::UserWord()
{
	for (int i=0;i<6;i++)
		mistakes[i] = ' ';
};
void UserWord:: makeUserWord(DictionaryWord dword)
{
		word=dword.getWord();
	    for (int i=0;i<dword.getWord().length();i++)
		word[i] = '-';
};

void UserWord::putMistake(int curMisses)
{
	mistakes[curMisses]=letter;
};
bool UserWord:: checkLetter(DictionaryWord dword)
{
	enterLetter();
	bool curStatus = false;
	for (int i=0;i<dword.getWord().length();i++)
		if (dword.getWord()[i]==letter)
			curStatus = true;
	return curStatus;
};
void UserWord:: enterLetter()
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
void UserWord:: putLetter(DictionaryWord dword)
{
	for (int i=0;i<dword.getWord().length();i++)
	{
		if (letter==dword.getWord()[i])
		{
			word[i] = letter;
		}
	}
};


