#include "player.h"

#include <iostream>

using namespace std;

void main ()
{
	Desk d;
	for(int i=0;i<32;i++)
		cout<<d.figure[i]->getX()<<" "<<d.figure[i]->getY()<<" "<<d.figure[i]->getStep()<<endl;
	cout<<d.figure[16]->canFigureTurn(1,4,d)<<endl;
	cout<<d.figure[4]->canFigureTurn(3,3,d)<<endl;
	cout<<d.figure[0]->canFigureTurn(1,3,d)<<endl;
	cout<<d.figure[1]->canFigureTurn(8,1,d)<<endl;
	return;
}