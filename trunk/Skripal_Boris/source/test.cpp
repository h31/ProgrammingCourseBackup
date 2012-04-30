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
		test.desk.makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		whitePlayerTurn=!whitePlayerTurn;
	}

	for(int i=0;i<32;i++)
	{
		if(test.desk.getFigure(i)->getX()==6 && test.desk.getFigure(i)->getY()==1 && test.desk.getFigure(i)->getColour()==true &&test.desk.getFigure(i)->isEat()==false && test.desk.getFigure(i)->getType()==rook && test.desk.getFigure(i)->getStep()==1)
			if(test.desk.wKing->getX()==7 && test.desk.wKing->getY()==1 && test.desk.wKing->getStep()==1)
			{
				cout<<"castling test is true!"<<endl;
				test.desk.printPlayingBoard();
				return true;
			}
	}
	cout<<"castling test is faled"<<endl;
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
		test.desk.makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		whitePlayerTurn=!whitePlayerTurn;
	}
	
	for(int i=0;i<32;i++)
		if(test.desk.getFigure(i)->getX()==3 && test.desk.getFigure(i)->getY()==6 && test.desk.getFigure(i)->getType()==pawn && test.desk.getFigure(i)->isEat()==false && test.desk.getFigure(i)->getColour()==true)
		{
			cout<<" en passant is true!"<<endl;
			test.desk.printPlayingBoard();
			return true;
		}
	cout<<" en passant is false"<<endl;
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
		test.desk.makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		whitePlayerTurn=!whitePlayerTurn;
	}
	
	for(int i=0;i<32;i++)
		if(test.desk.getFigure(i)->getX()==1 && test.desk.getFigure(i)->getY()==8 && test.desk.getFigure(i)->getType()!=pawn && test.desk.getFigure(i)->isEat()==false && test.desk.getFigure(i)->getColour()==true)
		{
			cout<<" chance pawn is true"<<endl;
			test.desk.printPlayingBoard();
			return true;
		}
	cout<<" chance pawn is false"<<endl;
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
		test.desk.makeFigureTurn(startX,startY,finishX,finishY,whitePlayerTurn);
		if(test.desk.checkShah(whitePlayerTurn)==true)
		{
			cout<<"shah is true!"<<endl;
			test.desk.printPlayingBoard();
			return true;
		}
		whitePlayerTurn=!whitePlayerTurn;
	}
	test.desk.printPlayingBoard();
	cout<<"shah is false"<<endl;
	return false;
}

bool Test::tests()
{
	int numberOfTest=9;

	cout<<"Tests!"<<endl;
	while(numberOfTest >5)
	{
		cout<<"If you want test castling enter 1"<<endl<<
		"If you want test chanche pawn enter 2"<<endl<<
		"If you want test en passant enter 3"<<endl<<
		"If you want test shah enter 4"<<endl<<
		"If you want exit press 5"<<endl;
	
			cin>>numberOfTest;
		if(numberOfTest == 1)
			{
			testCastling();
			numberOfTest=9;
			}
		if(numberOfTest==2)
			{
			testChanchePawn();
			numberOfTest=9;
			}
		if(numberOfTest==3)
			{
			testEnPassant();
			numberOfTest=9;
			}
		if(numberOfTest==4)
			{
			testShah();
			numberOfTest=9;
			}
		if(numberOfTest==5)
			return true;
		
	}
}
