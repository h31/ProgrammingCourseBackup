#include "player.h"

#include <iostream>

using namespace std;

void main ()
{
	Desk d;
	for(int i=0;i<32;i++)
		cout<<d.getFigure(i)->getX()<<" "<<d.getFigure(i)->getY()<<" "<<d.getFigure(i)->getStep()<<endl;
	cout<<d.getFigure(16)->canFigureTurn(1,4,d)<<endl;
	cout<<d.getFigure(4)->canFigureTurn(3,3,d)<<endl;
	cout<<d.getFigure(0)->canFigureTurn(1,3,d)<<endl;
	cout<<d.getFigure(1)->canFigureTurn(8,1,d)<<endl;
	return;
}