#ifndef _test_h_
#define _test_h_

#include"player.h"
#include "testsvariants.h"
#include <io.h>
#include <iostream>
#include <fstream>

using namespace std;
class Test: public QObject
{
    Q_OBJECT
private:
	/*void printListOfFigures();
	bool testFiguresTurn();*/
	bool testEnPassant();
	bool testCastling();
	bool testChanchePawn();
	bool testShah();
    bool testMat();
public:
	bool tests();
signals:
    void testIsTrue();
    void testIsFalse();
};

#endif
