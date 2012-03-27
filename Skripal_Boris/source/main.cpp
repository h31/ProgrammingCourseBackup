#include "player.h"

#include <iostream>

using namespace std;

void main ()
{
	Desk d;
	for(int i=0;i<32;i++)
		cout<<d.figure[i]->coordinateX<<" "<<d.figure[i]->coordinateY<<" "<<d.figure[i]->steps<<endl;
	cout<<d.figure[16]->canFigureTurn(1,4,d.figure)<<endl;
	cout<<d.figure[4]->canFigureTurn(3,3,d.figure)<<endl;
	cout<<d.figure[0]->canFigureTurn(1,3,d.figure)<<endl;
	cout<<d.figure[1]->canFigureTurn(8,1,d.figure)<<endl;
	return;
}