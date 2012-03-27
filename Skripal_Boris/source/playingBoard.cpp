#include "playingBoard.h"

Desk::Desk()
{
	figure = new Figure *[32];
	createNewDesk();
}

void Desk::createNewDesk()
{//расстановка ладей
	figure[0] = new Rook(1,1,true);

	figure[1] = new Rook(8,1,true);

	figure[2] = new Rook(1,8,false);

	figure[3] = new Rook(8,8,false);
//расстановка коней

	figure[4] = new Horse(2,1,true);

	figure[5] = new Horse(7,1,true);

	figure[6] = new Horse(2,8,false);

	figure[7] = new Horse(7,8,false);
//расстановка слонов
	figure[8] = new Elephant(3,1,true);

	figure[9] = new Elephant(6,1,true);

	figure[10] = new Elephant(3,8,false);

	figure[11] = new Elephant(6,8,false);
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

Desk::~Desk()
{
	/*for(int i=0;i<32;i++)
		delete figure[i];*/
	delete figure;
}

bool Desk::checkShah(bool whitePlayer)
{
	return false;
}

//bool Desk::Castling(int xCoordinate,int yCoordinate)
//{
//	
//}