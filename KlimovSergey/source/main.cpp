#include "Game.h"
#include "SquareTest.h"
#include "OpenFileTest.h"
#include "TestResult.h"

using namespace std;

int main(void)
{
	Field f;
	Game g;
	Player p;
	g.Start(f,"test12.txt",p);
	cout<<f.height<<" "<<f.width<<endl;
	p.ChangeStat(1,f,0,0);
	p.ChangeStat(2,f.map[1][1]);
	f.show();
	SquareTest sqt;
	sqt.testGetStat(f.map[2][2], 2);
	OpenFileTest oft;
	oft.openTest(f);
	TestResult test;
	test.failedTest();
	test.successTest();
	return 0;
}