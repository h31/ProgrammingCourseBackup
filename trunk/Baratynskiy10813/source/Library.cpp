#include "Library.h"
#include <ctime>
int Library::numberOfWords(ifstream &in)
{
		in.seekg(0, ios::end);
        const int numOfWords = in.tellg();
		in.seekg(0, ios::beg);
		return numOfWords;
};
BasicWord Library::takeWord(ifstream &in)
{
	if (in.fail())
	{
		cout << "������ ����� �� ����������!" << endl;
    }
	else
	{
		srand(time(NULL));
		int numOfWords = numberOfWords(in);
		randNum = rand() % numOfWords;
		int i = 0;
		while (i != randNum)
		{
			in>>word.word;
		    i++;
		}
     }
	return word;
};
BasicWord Library::takeWordOfLang()
{
	int choice;
	cout<<"�������� ����(1. ������� 2. english)"<<endl;
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