#include "Game.h"
bool Game:: checkLetter()
{
	bool curStatus = false;
	for (int i=0;i<word.word.length();i++)
		if (word.word[i]==word.letter)
			curStatus = true;
	return curStatus;
};
void Game:: enterLetter()
{
	bool status = false;
	cout<<"Enter the letter: ";
	cin>>word.letter;
	for (int i=0;i<man.maxMisses;i++)
		if (word.letter==word.mistakes[i])
			status = true;
	if (status == true)
	{
		cout<<"You've entered this letter before! "<<endl;
		enterLetter();
	}
};
void Game:: putLetter()
{
	for (int i=0;i<word.word.length();i++)
	{
		if (word.letter==word.word[i])
		{
			word.mask[i] = word.letter;
		}
	}
};
bool Game::isWon()
{
	if (word.mask == word.word)
		return true;
	else return false;
};
bool Game::isLose()
{
	if (man.curMisses==man.maxMisses)
		return true;
	else return false;
};
bool Game::playAgain()
{
	char choice = 'y';
	do 
	{
		cout<<"Do you want to play again? Enter 'y' or 'n': ";
        cin>>choice;
    } 
	while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y');
	return (choice == 'y' || choice == 'Y');
};
void Game::reset()
{
	man.curMisses=0;
	for (int i=0;i<=man.maxMisses;i++)
	{
		man.man[i] = ' ';
		word.mistakes[i] = ' ';
	}
};
int Game::chooseHowToPlay()
{
	int var;
	cout<<"Do you want to put your own word(1), or do you want to load it from file(2)?\n"<<
		"Put 1 or 2: ";
	cin>>var;
	return var;
};
int Game::play()
{
	if (chooseHowToPlay() == 1)
	{
		cout<<"Enter the word:"<<endl;
	    cin>>word.word;
	}
	else word.word = lib.takeWord();
	man.drawMan();
	word.makeMask();
	cout<<word.mask<<endl;
	while (man.curMisses<man.maxMisses)
	{
		enterLetter();
		if (checkLetter() == true)
			putLetter();
		else
		{
			cout<<"There is no such letter! "<<endl;
			man.curMisses++;
			word.putMistake(man.curMisses);
		}
		cout<<word.mask<<endl;
		cout<<"These letters were used: ";
		for (int i=0;i<man.maxMisses;i++)
			cout<<word.mistakes[i]<<" ";
		man.createMan();
		man.drawMan();
		if (isWon())
		{
			cout<<"Congratulations! You win!"<<endl;
			if (playAgain() == true)
			{
				reset();
				play();
			}
			return 0;
		}
		if (isLose())
		{
			cout<<"Loser! You lost!"<<endl;
			cout<<"The word was "<<word.word<<endl;
			if (playAgain() == true)
			{
				reset();
				play();
			}
			return 0;
		}
	}
};