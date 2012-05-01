#include "Library.h"
#include <ctime>
Library::Library()
{
	word = new DictionaryWord;
};
Library::~Library()
{
	delete [] word;
};
int Library::numberOfWords(ifstream &in)
{
		in.seekg(0, ios::end);
        const int numOfWords = in.tellg();
		in.seekg(0, ios::beg);
		cout<<numOfWords;
		return numOfWords;
};
DictionaryWord* Library::takeWord(ifstream &in)
{
	if (in.fail())
	{
		cout << "Такого файла не существует!" << endl;
    }
	else
	{
		srand(time(NULL));
		int numOfWords = numberOfWords(in);
		randNum = rand() % numOfWords;
		int i = 0;
		while (i != randNum)
		{
			in>>word->word;
		    i++;
		}
     }
	return word;
};
DictionaryWord* Library::takeWordOfLang()
{
	int choice;
	cout<<"Выберите язык(1. русский 2. english)"<<endl;
	cin>>choice;
	if (choice == 1)
	{
		ifstream in1("C:\\rus_words.txt");
		word=takeWord(in1);
	}
	else
	{
		ifstream in2("C:\\eng_words.txt");
		word=takeWord(in2);
	}
	return word;
};