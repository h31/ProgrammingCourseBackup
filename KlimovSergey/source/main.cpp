#include "Game.h"
//#include "Field.h"

using namespace std;

int main(void)
{
	Field f;
	//f.loadField("test12.txt");
	f.loadComplete("ctest1.txt");
	//cout<<f.map[1][1]<<endl;
	//ifstream fin("ctest1.txt");
	Game g;
	Player p;
	//g.Start(f,"test12.txt",p);
	//cout<<p.ChangeStat(145,f.map[0][0])<<endl;
	cout<<f.height<<" "<<f.width<<endl;
	p.ChangeStat(0,f,0,0);
	//p.ChangeStat(0,f.map[1][1]);
	f.show();
	//cout<</*f.map[1][1]*/f.height<<endl;
	return 0;
}