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
bool Test::test1()
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
bool Test::test2()
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
bool Test::test3()
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
bool Test::test4()
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
bool Test::test5()
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
bool Test::test6()
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
	if (test1() & test2() & test3() & test4() & test5() & test6())
		return true;
	else
		return false;
};