#include "player.h"
#include "test.h"

#include <iostream>

using namespace std;

void main ()
{
	Player p;
	Test tests;

	//tests.testCastling();
	//tests.testEnPassant();
	//tests.testChanchePawn();
	//tests.testShah();
	tests.tests();
	cout<<"Game run now!"<<endl<<endl;
	p.makeGame();
	return;
}