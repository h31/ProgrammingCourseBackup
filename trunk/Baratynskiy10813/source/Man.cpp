#include "Man.h"
Man:: Man()
{
	maxMisses=6;
	curMisses=0;
	for (int i=0;i<=maxMisses;i++)
	{
		man[i] = ' ';
	}
};
void Man:: createMan()
{
	switch(curMisses)
	{
		case 1:
	man[1] = 'O';
	break;
		case 2:
	man[2] = '|';
	break;
		case 3:
	man[3] = '/';
	break;
		case 4:
	man[4] = '\\';
	break;
		case 5:
	man[5] = '/';
	break;
		case 6:
	man[6] = '\\';
	break;
	}
};
void Man:: drawMan()
{
	cout<<endl;
	cout<<"  +-----+"<<endl;
	cout<<"  |     |"<<endl;
	cout<<"  |     "<<man[1]<<endl;
	cout<<"  |    "<<man[3]<<man[2]<<man[4]<<endl;
	cout<<"  |    "<<man[5]<<" "<<man[6]<<endl;
	cout<<"  |"<<endl;
	cout<<"  |_______"<<endl;
};