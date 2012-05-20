#include "Game.h"
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
	f.show();
	OpenFileTest oft;
	//oft.openTest(f);
	TestResult test;
	test.failedTest();
	test.successTest();
	return 0;
}