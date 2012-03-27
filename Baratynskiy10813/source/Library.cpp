#include "Library.h"
int Library::chooseTheme()
{
	cout<<" You can choose one of these themes(press 1,2 or 3):"<<endl;
	cout<<"1. All words(without any theme)\n"<<"2. Sport\n"<<"3.Contries\n"<<endl;
	cin>>var;
	return var;
};
string Library::takeWord()
{
	srand(time(NULL));
	string word;
	ifstream in("C:\\all_words.txt");
	if (in.fail())
	{
		cout << "No such file or directory" << endl;
    }
	else
	{
		in.seekg(0, ios::end);
        const int lengthOfFile = in.tellg();
		in.seekg(0, ios::beg);
		randNum = rand() % lengthOfFile;
		int i = 0;
		while (i != randNum)
		{
			in>>word;
		    i++;
		}
     }
	return word;
};