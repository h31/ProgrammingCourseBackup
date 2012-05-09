#include "test.h"

bool Test::testCastling()
{
	ifstream fout("castlingTest.txt");
	int startX,startY,finishX,finishY;
	bool whitePlayerTurn=true;
	Player test;

	while(!fout.eof())
	{
		fout>>startX>>startY>>finishX>>finishY;
        test.desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		whitePlayerTurn=!whitePlayerTurn;
	}

	for(int i=0;i<32;i++)
	{
        if(test.desk->getFigure(i)->getX()==3 && test.desk->getFigure(i)->getY()==1 && test.desk->getFigure(i)->getColour()==true &&test.desk->getFigure(i)->isEat()==false && test.desk->getFigure(i)->getType()==rook && test.desk->getFigure(i)->getStep()==1)
            if(test.desk->wKing->getX()==2 && test.desk->wKing->getY()==1 && test.desk->wKing->getStep()==1)
			{
//				cout<<"castling test is true!"<<endl;
//                test.desk->printPlayingBoard();
                testIsTrue();
                test.desk->createNewDesk();
				return true;
			}
	}
//	cout<<"castling test is faled"<<endl;
    testIsFalse();
    test.desk->createNewDesk();
	return false;
}

bool Test::testEnPassant()
{
	ifstream fout("enPassant.txt");
	int startX,startY,finishX,finishY;
	bool whitePlayerTurn=true;
	Player test;

	while(!fout.eof())
	{
		fout>>startX>>startY>>finishX>>finishY;
        test.desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		whitePlayerTurn=!whitePlayerTurn;
	}
	
	for(int i=0;i<32;i++)
        if(test.desk->getFigure(i)->getX()==3 && test.desk->getFigure(i)->getY()==6 && test.desk->getFigure(i)->getType()==pawn && test.desk->getFigure(i)->isEat()==false && test.desk->getFigure(i)->getColour()==true)
		{
//			cout<<" en passant is true!"<<endl;
//            test.desk->printPlayingBoard();
            testIsTrue();
            test.desk->createNewDesk();
			return true;
		}
//	cout<<" en passant is false"<<endl;
    test.desk->createNewDesk();
	return false;
}

bool Test::testChanchePawn()
{
	ifstream fout("chanchePawn.txt");
	int startX,startY,finishX,finishY;
	bool whitePlayerTurn=true;
	Player test;

	while(!fout.eof())
	{
		fout>>startX>>startY>>finishX>>finishY;
        test.desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		whitePlayerTurn=!whitePlayerTurn;
	}
	
	for(int i=0;i<32;i++)
        if(test.desk->getFigure(i)->getX()==1 && test.desk->getFigure(i)->getY()==8 && test.desk->getFigure(i)->getType()!=pawn && test.desk->getFigure(i)->isEat()==false && test.desk->getFigure(i)->getColour()==true)
		{
//			cout<<" chance pawn is true"<<endl;
//            test.desk->printPlayingBoard();
            testIsTrue();
            test.desk->createNewDesk();
			return true;
		}
//	cout<<" chance pawn is false"<<endl;
    testIsFalse();
    test.desk->createNewDesk();
	return false;
}

bool Test::testShah()
{
	ifstream fout("shah.txt");
	int startX,startY,finishX,finishY;
	bool whitePlayerTurn=true;
	Player test;

	while(!fout.eof())
	{
		fout>>startX>>startY>>finishX>>finishY;
        test.desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
        if(test.desk->checkShah(whitePlayerTurn)==true)
		{
//			cout<<"shah is true!"<<endl;
//            test.desk->printPlayingBoard();
            testIsTrue();
            test.desk->createNewDesk();
			return true;
		}
		whitePlayerTurn=!whitePlayerTurn;
	}
//    test.desk->printPlayingBoard();
//	cout<<"shah is false"<<endl;
    test.desk->createNewDesk();
    testIsFalse();
	return false;
}

bool Test::testMat()
{
    ifstream fout("mat.txt");
    int startX,startY,finishX,finishY;
    bool whitePlayerTurn=true;
    Player test;

    while(!fout.eof())
    {
        fout>>startX>>startY>>finishX>>finishY;
        test.desk->makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
        if(test.desk->checkMat(whitePlayerTurn)==true)
        {
//			cout<<"shah is true!"<<endl;
//            test.desk->printPlayingBoard();
            testIsTrue();
            test.desk->createNewDesk();
            return true;
        }
        whitePlayerTurn=!whitePlayerTurn;
    }
//    test.desk->printPlayingBoard();
//	cout<<"shah is false"<<endl;
    test.desk->createNewDesk();
    testIsFalse();
    return false;
}

bool Test::tests()
{
	int numberOfTest=9;

//	cout<<"Tests!"<<endl;
//	while(numberOfTest >5)
	{
//		cout<<"If you want test castling enter 1"<<endl<<
//		"If you want test chanche pawn enter 2"<<endl<<
//		"If you want test en passant enter 3"<<endl<<
//		"If you want test shah enter 4"<<endl<<
//		"If you want exit press 5"<<endl;
	
//			cin>>numberOfTest;
        testsVariants *tdial = new testsVariants;
        tdial->exec();
       numberOfTest = tdial->getTypeOfTest();
       delete tdial;
		if(numberOfTest == 1)
			{
            return testCastling();
			}
		if(numberOfTest==2)
			{
            return testChanchePawn();
			}
		if(numberOfTest==3)
			{
            return testEnPassant();
			}
		if(numberOfTest==4)
			{
            return testShah();
			}
		if(numberOfTest==5)
        {
           return testMat();
        }
		
	}
}
