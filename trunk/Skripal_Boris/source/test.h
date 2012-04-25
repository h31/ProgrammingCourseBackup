#ifndef _test_h_
#define _test_h_

#include"player.h"

#include <io.h>
#include <iostream>
#include <fstream>

using namespace std;
class Test
{
public:
	void printListOfFigures();
	bool testFiguresTurn();
	bool testEnPassant();
	bool testCastling();
	bool testChanchePawn();
	bool testShah();
	bool testMat();
};

#endif