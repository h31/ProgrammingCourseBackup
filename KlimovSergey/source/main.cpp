#include "Game.h"
//#include "Field.h"

using namespace std;

int main(void)
{
	Field f;
	Game g;
	Player p;
	g.Start(f,"test12.txt",p);
	//cout<<p.ChangeStat(145,f.map[0][0])<<endl;
	cout<<f.height<<" "<<f.width<<endl;
	p.ChangeStat(1,f,0,0);
	p.ChangeStat(2,f.map[1][1]);
	f.show();
	return 0;
}