#include "UserWord.h"
UserWord::UserWord()
{
	for (int i=0;i<6;i++)
		mistakes[i] = ' ';
};
void UserWord::enterWord()
{
	cout<<"¬ведите слово: "<<endl;
	cin>>word;
};
