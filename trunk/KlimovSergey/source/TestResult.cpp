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
			p.ChangeStat(1,f.map[j][i]);
	p.ChangeStat(1,f.map[0][1]);
	p.ChangeStat(1,f.map[0][2]);
	p.ChangeStat(1,f.map[0][6]);
	p.ChangeStat(1,f.map[0][7]);
	for(int i=0;i<4;i++)
		p.ChangeStat(1,f.map[1][i]);
	for(int i=5;i<9;i++)
		p.ChangeStat(1,f.map[1][i]);
	for(int i=1;i<8;i++)
		p.ChangeStat(1,f.map[5][i]);
	for(int i=2;i<7;i++)
		p.ChangeStat(1,f.map[6][i]);
	for(int i=3;i<6;i++)
		p.ChangeStat(1,f.map[7][i]);
	p.ChangeStat(1,f.map[8][4]);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(f.map[i][j].status != 1)
				p.ChangeStat(2,f.map[i][j]);
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
			p.ChangeStat(1,f.map[j][i]);
	p.ChangeStat(1,f.map[0][1]);
	p.ChangeStat(1,f.map[0][2]);
	p.ChangeStat(1,f.map[0][6]);
	p.ChangeStat(1,f.map[0][7]);
	for(int i=0;i<4;i++)
		p.ChangeStat(1,f.map[1][i]);
	for(int i=5;i<9;i++)
		p.ChangeStat(1,f.map[1][i]);
	for(int i=1;i<8;i++)
		p.ChangeStat(1,f.map[5][i]);
	for(int i=2;i<7;i++)
		p.ChangeStat(1,f.map[6][i]);
	for(int i=3;i<6;i++)
		p.ChangeStat(1,f.map[7][i]);
	
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(f.map[i][j].status != 1)
				p.ChangeStat(2,f.map[i][j]);
	f.show();
	g.Check(f,"cheart.txt");
}