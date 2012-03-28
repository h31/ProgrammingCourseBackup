#include "Game.h"
Game::Game()
{
	bword = new BasicWord;
	man = new Man;
};
Game::~Game()
{
	delete[] bword;
	delete[] man;
};
bool Game::isWon()
{
	if (bword->mask == bword->word)
		return true;
	else return false;
};
bool Game::isLose()
{
	if (man->curMisses==man->maxMisses)
		return true;
	else return false;
};
bool Game::playAgain()
{
	char choice = 'y';
	do 
	{
		cout<<"������ �� �� ������� ��� ���? ������� 'y' ��� 'n': ";
        cin>>choice;
    } 
	while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y');
	return (choice == 'y' || choice == 'Y');
};
void Game::reset()
{
	man->curMisses=0;
	for (int i=0;i<=man->maxMisses;i++)
	{
		man->man[i] = ' ';
		bword->mistakes[i] = ' ';
	}
};
int Game::chooseHowToPlay()
{
	int var;
	cout<<"�� ������ ������ ����������� �����(1), ��� ������, ����� ��� ����������� �� �����(2)?\n"<<
		"������� 1 ��� 2: ";
	cin>>var;
	return var;
};
int Game::play()
{
	if (chooseHowToPlay() == 1)
	{
		uword.enterWord();
		bword = &uword;
	}
	else 
	{
		dword.takeTheWord();
		bword = &dword;
	}
	man->makeMan();
	bword->makeMask();
	cout<<bword->mask<<endl;
	while (man->curMisses<man->maxMisses)
	{
		if (bword->checkLetter() == true)
			bword->putLetter();
		else
		{
			cout<<"����� ����� ���! "<<endl;
			man->curMisses++;
			bword->putMistake(man->curMisses);
		}
		cout<<bword->mask<<endl;
		cout<<"�����, ��������� ������: ";
		for (int i=0;i<man->maxMisses;i++)
			cout<<bword->mistakes[i]<<" ";
		man->makeMan();
		if (isWon())
		{
			cout<<"�� ��������!"<<endl;
			if (playAgain() == true)
			{
				reset();
				play();
			}
			return 0;
		}
		if (isLose())
		{
			cout<<"�� ���������!"<<endl;
			cout<<"���������� �����: "<<bword->word<<endl;
			if (playAgain() == true)
			{
				reset();
				play();
			}
			return 0;
		}
	}
};