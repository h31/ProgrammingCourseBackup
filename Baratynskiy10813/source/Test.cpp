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
		cout << "Такого файла не существует!" << endl;
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
		cout<<"Первый тест успешно пройден!"<<endl;
		return true;
	}
	else
	{
		cout<<"Первый тест не пройден!"<<endl;
		return false;
	}
};
bool Test::checkLetter()
{
	cout<<"Введите b, пожалуйста:";
	uword->enterLetter();
	if (uword->letter == 'b')
	{
		cout<<"Второй тест успешно пройден!"<<endl;
		return true;
	}
	else
	{
		cout<<"Второй тест не пройден!"<<endl;
		return false;
	}
};
bool Test::testCheckLetterMethod()
{
	cout<<"Введите 'b', пожалуйста: ";
	if (uword->checkLetter(*takeTheThirdWord()) == false)
	{
		cout<<"Третий тест не пройден!"<<endl;
		return false;
	}
	else
	{
		cout<<"Третий тест успешно пройден!"<<endl;
		return true;
	}
};
bool Test::checkPutLetter()
{
	word->word=takeTheThirdWord()->word;
	uword->makeUserWord(*word);
	cout<<"Введите 'a',пожалуйста: ";
	if (uword->checkLetter(*word) == true)
			uword->putLetter(*word);
	if (uword->word[0] == 'a' & uword->word[2] == 'a')
	{
		cout<<"Четвертый тест успешно пройден!"<<endl;
		return true;
	}
	else
	{
		cout<<"Четвертый тест не пройден!"<<endl;
		return false;
	}
};
bool Test::checkIsWon()
{
	word->word=takeTheThirdWord()->word;
	uword->word=word->word;
	if (game->isWon() == true)
	{
		cout<<"Пятый тест успешно пройден!"<<endl;
		return true;
	}
	else
	{
		cout<<"Пятый тест не пройден!"<<endl;
		return false;
	}
};
bool Test::checkIsLose()
{
	word->word=takeTheThirdWord()->word;
	game->man->curMisses=6;
	if (game->isLose())
	{
		cout<<"Шестой тест успешно пройден!"<<endl;
		return true;
	}
	else
	{
		cout<<"Шестой тест не пройден!"<<endl;
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