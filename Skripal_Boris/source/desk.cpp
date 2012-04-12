#include "desk.h"

Desk::Desk()
{
	figure = new Figure *[32];
	playingBoard = new PlayingBoard *[8];
	for(int i=0;i<8;i++)
		playingBoard[i] = new PlayingBoard[8];
	for(int i=0;i<8;i++)
		for(int k=0;k<8;k++)
		{
			if(k%2==0 && i%2==0 || k%2==1 && i%2==1)
				playingBoard[i][k].isCellWhite=false;
			else
				playingBoard[i][k].isCellWhite=true;
			playingBoard[i][k].figuresType=none;
			playingBoard[i][k].figureOnCell=NULL;
		}

	createNewDesk();

	for(int i=0;i<32;i++)
		if(figure[i]->getX()==5 && figure[i]->getY()==1 && figure[i]->getColour()==true)
			wKing = figure[i];
	for(int i=0;i<32;i++)
		if(figure[i]->getX()==5 && figure[i]->getY()==8 && figure[i]->getColour()==false)
			bKing = figure[i];
}

void Desk::createNewDesk()
{//расстановка ладей
	figure[0] = new Rook(1,1,true);

	figure[1] = new Rook(8,1,true);

	figure[2] = new Rook(1,8,false);

	figure[3] = new Rook(8,8,false);
//расстановка коней

	figure[4] = new Knight(2,1,true);

	figure[5] = new Knight(7,1,true);

	figure[6] = new Knight(2,8,false);

	figure[7] = new Knight(7,8,false);
//расстановка слонов
	figure[8] = new Bishop(3,1,true);

	figure[9] = new Bishop(6,1,true);

	figure[10] = new Bishop(3,8,false);

	figure[11] = new Bishop(6,8,false);
//расстановка королей
	figure[12] = new King(5,1,true);

	figure[13] = new King(5,8,false);
//расстановка ферзей
	figure[14] = new Queen(4,1,true);

	figure[15] = new Queen(4,8,false);
//расстановка пешек
	for(int i=1;i<9;i++)
	{
		figure[15+i] = new Pawn(i,2,true);
	}

	for(int i=1;i<9;i++)
	{
		figure[23+i] = new Pawn(i,7,false);
	}

	
	return;
}
//проверка на совпадение цветов фигур, при совпадении или отсутствии -
//bool Desk::getFigure(int x, int y, bool whiteColour)
//{
//	for(int i=0;i<32;i++)
//		if(figure[i]->isWigureEat==false)
//			if(figure[i]->whiteColour != whiteColour)
//				if(figure[i]->coordinateX == x)
//					if(figure[i]->coordinateY ==y)
//						return true;
//	return false;
//}
////проверка на наличие фигуры, при наличие +
//bool Desk::getFigure(int x, int y)
//{
//	for(int i=0;i<32;i++)
//		if(figure[i]->isWigureEat==false)
//			if(figure[i]->coordinateX == x)
//				if(figure[i]->coordinateY ==y)
//					return true;
//	return false;
//}

void Desk::refreshDesk()
{
	for(int i=0;i<8;i++)
		for(int k=0; k<8;k++)
			playingBoard[i][k].figureOnCell=NULL;

	for(int i=0;i<32;i++)
	{
		playingBoard[figure[i]->getX()][figure[i]->getY()].figuresType=figure[i]->getType();
		playingBoard[figure[i]->getX()][figure[i]->getY()].isFigureWhite=figure[i]->getColour();
		playingBoard[figure[i]->getX()][figure[i]->getY()].figureOnCell=figure[i];
	}
	return;
}
Desk::~Desk()
{
	/*for(int i=0;i<32;i++)
		delete figure[i];*/
	delete figure;
}

void Desk::chanchePawn(const bool whiteColour)
{
	int type;

	for(int i=0;i<32;i++)
		if(figure[i]->getType() == pawn &&figure[i]->getY() == 7 && figure[i]->getColour() == true)
		{
			do
			{
			cout<<"Enter type of figure: 1 queen, 2 rook, 3 knight, 4 bishop"<<endl;
			cin>>type;
			}while(type>4);
			setFigure(i,type);
		}

	for(int i=0;i<32;i++)
		if(figure[i]->getType() == pawn &&figure[i]->getY() == 1 && figure[i]->getColour() == false)
		{
			do
			{
			cout<<"Enter type of figure: 1 queen, 2 rook, 3 knight, 4 bishop"<<endl;
			cin>>type;
			}while(type>4);
			setFigure(i,type);
		}
	refreshDesk();
	return;
}

void Desk::setFigure(const int numberOfFigure,const  int type)
{
	switch(type)
	{
	case 1:
		{
			Figure *bufFigure;
			bufFigure = figure[numberOfFigure];
			figure[numberOfFigure] = new Queen(bufFigure->getX(),bufFigure->getY(),bufFigure->getColour());
			delete bufFigure;
			break;
		}
	case 2:
		{
			Figure *bufFigure;
			bufFigure = figure[numberOfFigure];
			figure[numberOfFigure] = new Rook(bufFigure->getX(),bufFigure->getY(),bufFigure->getColour());
			delete bufFigure;
			break;
		}
	case 3:
		{
			Figure *bufFigure;
			bufFigure = figure[numberOfFigure];
			figure[numberOfFigure] = new Knight(bufFigure->getX(),bufFigure->getY(),bufFigure->getColour());
			delete bufFigure;
			break;
		}
	case 4:
		{
			Figure *bufFigure;
			bufFigure = figure[numberOfFigure];
			figure[numberOfFigure] = new Bishop(bufFigure->getX(),bufFigure->getY(),bufFigure->getColour());
			delete bufFigure;
			break;
		}
	default:
		{
			break;
		}

	}
	return;
}

bool Desk::checkShah(const bool whitePlayer)
{
	Figure *king;
	if(whitePlayer == true)
		king = wKing;
	else
		king = bKing;
	for(int i=0;i<32;i++)
		if(figure[i]->canFigureTurn(king->getX(),king->getY(),*this)==true)
			return true;

	return false;
}

bool Desk::checkMat(const bool whitePlayer)
{
	Figure *king;
	if(whitePlayer == true)
		king = wKing;
	else
		king = bKing;
	for(int x=1;x<9;x++)
		for(int y=1;y<9;y++)
			for(int i=0;i<32;i++)
				if(king->canFigureTurn(x,y,*this)==true && figure[i]->getColour()!=king->getColour() &&figure[i]->canFigureTurn(x,y,*this)==false )
					return false;
	return true;
}
bool Desk::castling(const int startX, const int startY,const int finishX,const int finishY,const bool whitePlayer)
{
	Figure *king;
	if(whitePlayer == true)
		king = wKing;
	else
		king = bKing;

	if(king->getX()==startX && king->getY()==startY)
		if(king->getStep()==0 && abs(king->getX()-finishX)==2 && king->getY()==finishY)
		{
			for(int i=0; i<32;i++)
				if(figure[i]->getX()==(king->getX()+(finishX-startX)/2) && figure[i]->getY()==startY)
					return false;
			Figure *rook;
			bool haveRook=false;
			if(finishX>startX)
			{
				for(int i=0;i<32;i++)
					if(figure[i]->getX()==8 && figure[i]->getY()==1)
					{
						rook=figure[i];
						haveRook = true;
					}
			}
			else
			{
				for(int i=0;i<32;i++)
					if(figure[i]->getX()==1 && figure[i]->getY()==1)
					{
						haveRook = true;
						rook=figure[i];
					}
			}
			
			if(haveRook == false)
				return false;
			if(rook->canFigureTurn(finishX,finishY,*this)==false)
				return false;
			else
			{
				rook->setX((finishX-startX)/2);
				king->setX(finishX);
				refreshDesk();
				return true;
			}
		}
	return false;
}

bool Desk::enPassant(const int startX, const int startY, const int finishX,const  int finishY,const  bool whitePlayer)
{
	if(abs(startX-finishX)!=1)
		return false;
	if(abs(startY-finishY)!=1)
		return false;
	if(finishY<startY && whitePlayer==false)
		return false;
	if(finishY>startY && whitePlayer==true)
		return false;
	for(int i=0;i<32;i++)
		if(figure[i]->getX()==startX && figure [i]->getY()==startY && figure[i]->getType()==pawn && figure[i]->getColour()==whitePlayer && figure[i]->isEat()==false)
		{
			for(int k=0;k<32;k++)
				if(figure[k]->getX()==finishX && figure[k]->getY()==finishY && figure[k]->isEat()==true)
					return false;
			for(int k=0;k<32;k++)
				if(figure[k]->getX()==finishX && figure[k]->getY()==startY && figure[k]->getColour()!=figure[i]->getColour() && figure[k]->isEat()==false && figure[k]->getStep()==1)
				{
					figure[k]->eatFigure(true);
					figure[i]->setX(finishX);
					figure[i]->setY(finishY);
					figure[i]->increaceSteps(true);
					refreshDesk();
					return true;
				}
		}

	return false;
}

Figure* Desk::getFigure(const int number) const
{
	return figure[number];
}