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