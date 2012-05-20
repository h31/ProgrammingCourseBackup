#include "TestResult.h"
#include "Game.h"

TestResult::TestResult()
{
}


TestResult::~TestResult()
{
}

void TestResult::successTest()
{
	Field f;
	Game g;
	Player p;
	g.Start(f,"heart.txt",p);
	for(int i=0;i<9;i++)
		for(int j=2;j<5;j++)
			p.ChangeStat(1,f,i,j);
	p.ChangeStat(1,f,1,0);
	p.ChangeStat(1,f,2,0);
	p.ChangeStat(1,f,6,0);
	p.ChangeStat(1,f,7,0);
	for(int i=0;i<4;i++)
		p.ChangeStat(1,f,i,1);
	for(int i=5;i<9;i++)
		p.ChangeStat(1,f,i,1);
	for(int i=1;i<8;i++)
		p.ChangeStat(1,f,i,5);
	for(int i=2;i<7;i++)
		p.ChangeStat(1,f,i,6);
	for(int i=3;i<6;i++)
		p.ChangeStat(1,f,i,7);
	p.ChangeStat(1,f,4,8);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(f.getSqStat(i,j) != 1)
				p.ChangeStat(2,f,i,j);
	f.show();
	g.Check(f,"cheart.txt");
}

void TestResult::failedTest()
{
		Field f;
	Game g;
	Player p;
	g.Start(f,"heart.txt",p);
		for(int i=0;i<9;i++)
		for(int j=2;j<5;j++)
			p.ChangeStat(1,f,i,j);
	p.ChangeStat(1,f,1,0);
	p.ChangeStat(1,f,2,0);
	p.ChangeStat(1,f,6,0);
	p.ChangeStat(1,f,7,0);
	for(int i=0;i<4;i++)
		p.ChangeStat(1,f,i,1);
	for(int i=5;i<9;i++)
		p.ChangeStat(1,f,i,1);
	for(int i=1;i<8;i++)
		p.ChangeStat(1,f,i,5);
	for(int i=2;i<7;i++)
		p.ChangeStat(1,f,i,6);
	for(int i=3;i<6;i++)
		p.ChangeStat(1,f,i,7);

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(f.getSqStat(i,j) != 1)
				p.ChangeStat(2,f,i,j);
	f.show();
	g.Check(f,"cheart.txt");
}