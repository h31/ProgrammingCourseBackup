#include "Test.h"

Test::Test()
{
	word=new DictionaryWord;
	uword = new UserWord;
	game = new Game;
	man = new Man;
};
Test::~Test()
{
	delete[] word;
	delete[] uword;
	delete[] game;
	delete[] man;
};
DictionaryWord* Test::takeTheThirdWord()
{
	ifstream in("C:\\eng_words.txt");
	if (in.fail())
	{
		cout << "������ ����� �� ����������!" << endl;
    }
	else
	{
		for(int i=0;i<=2;i++)
			in>>word->word;
    }
	return word;
};
bool Test::checkTheWord()
{
	string str = "aback";
	if (takeTheThirdWord()->word == str)
	{
		cout<<"������ ���� ������� �������!"<<endl;
		return true;
	}
	else
	{
		cout<<"������ ���� �� �������!"<<endl;
		return false;
	}
};
bool Test::checkLetter()
{
	cout<<"������� b, ����������:";
	uword->enterLetter();
	if (uword->letter == 'b')
	{
		cout<<"������ ���� ������� �������!"<<endl;
		return true;
	}
	else
	{
		cout<<"������ ���� �� �������!"<<endl;
		return false;
	}
};
bool Test::testCheckLetterMethod()
{
	cout<<"������� 'b', ����������: ";
	if (uword->checkLetter(*takeTheThirdWord()) == false)
	{
		cout<<"������ ���� �� �������!"<<endl;
		return false;
	}
	else
	{
		cout<<"������ ���� ������� �������!"<<endl;
		return true;
	}
};
bool Test::checkPutLetter()
{
	word->word=takeTheThirdWord()->word;
	uword->makeUserWord(*word);
	cout<<"������� 'a',����������: ";
	if (uword->checkLetter(*word) == true)
			uword->putLetter(*word);
	if (uword->word[0] == 'a' & uword->word[2] == 'a')
	{
		cout<<"��������� ���� ������� �������!"<<endl;
		return true;
	}
	else
	{
		cout<<"��������� ���� �� �������!"<<endl;
		return false;
	}
};
bool Test::checkIsWon()
{
	word->word=takeTheThirdWord()->word;
	uword->word=word->word;
	if (game->isWon() == true)
	{
		cout<<"����� ���� ������� �������!"<<endl;
		return true;
	}
	else
	{
		cout<<"����� ���� �� �������!"<<endl;
		return false;
	}
};
bool Test::checkIsLose()
{
	word->word=takeTheThirdWord()->word;
	game->man->curMisses=6;
	if (game->isLose())
	{
		cout<<"������ ���� ������� �������!"<<endl;
		return true;
	}
	else
	{
		cout<<"������ ���� �� �������!"<<endl;
		return false;
	}
};
bool Test::fullTest()
{
	if (checkTheWord() & checkLetter() & testCheckLetterMethod() & checkPutLetter() & checkIsWon() & checkIsLose())
		return true;
	else
		return false;
};