#include "Game.h"
Game::Game()
{
	man = new Man;
	dword = new DictionaryWord;
	uword = new UserWord;
	lib = new Library;
};
Game::~Game()
{
	delete[] man;
	delete[] dword;
	delete[] uword;
	delete[] lib;
};
bool Game::isWon()
{
	if (uword->getWord() == dword->getWord())
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
		cout<<"Хотите ли Вы сыграть еще раз? Введите 'y' или 'n': ";
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
		uword->mistakes[i] = ' ';
	}
};
int Game::play()
{
	dword->setWord(lib->takeWordOfLang()->getWord());
	man->makeMan();
	uword->makeUserWord(*dword);
	cout<<uword->getWord()<<endl;
	while (man->curMisses<man->maxMisses)
	{
		if (uword->checkLetter(*dword) == true)
			uword->putLetter(*dword);
		else
		{
			cout<<"Такой буквы нет! "<<endl;
			man->curMisses++;
			uword->putMistake(man->curMisses);
		}
		cout<<uword->getWord()<<endl;
		cout<<"Буквы, введенные раньше: ";
		for (int i=0;i<man->maxMisses;i++)
			cout<<uword->mistakes[i]<<" ";
		man->makeMan();
		if (isWon())
		{
			cout<<"Вы выиграли!"<<endl;
			if (playAgain() == true)
			{
				reset();
				play();
			}
			return 0;
		}
		if (isLose())
		{
			cout<<"Вы проиграли!"<<endl;
			cout<<"Загаданное слово: "<<dword->getWord()<<endl;
			if (playAgain() == true)
			{
				reset();
				play();
			}
			return 0;
		}
	}
};