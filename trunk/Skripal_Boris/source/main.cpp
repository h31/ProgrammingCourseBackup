#include "player.h"
#include "test.h"

#include <iostream>

using namespace std;

void main ()
{
	Player p;
	Test tests;
	tests.testCastling();
	tests.testEnPassant();
	//p.makeGame();
	return;
}