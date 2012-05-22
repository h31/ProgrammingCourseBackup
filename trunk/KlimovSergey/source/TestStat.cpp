#include "TestStat.h"



TestStat::TestStat()
{
}

TestStat::~TestStat()
{
}

void TestStat::testSetter()
{
	Player p;
	Field f;
	Game g;
	g.Start(f,"heart.txt",p);
	int in;
	cout<<"Enter value to test setting status:"<<endl;
	cin>>in;
	p.ChangeStat(in,f,0,0);
	if(f.getSqStat(0,0) == in)
		cout<<"Successfull chainging status!"<<endl;
	else
		cout<<"Chainging status failed!"<<endl;
}