#include "Square3x3.h"
#include "Field.h"
//Выделяем квадрат
Square3x3::Square3x3(int ixRow, int ixCol)
{
	int xmax = 0;
	int ymax = 0;
	
	if (ixRow < 3 && ixCol < 3)
	{
		ymax = 0;
		xmax = 0;
	}
	else if (ixRow < 3 && ixCol < 6 && ixCol > 2)
	{
		ymax = 3;
		xmax = 0;
	}
	else if (ixRow < 3 && ixCol < 9 && ixCol > 5)
	{
		ymax = 6;
		xmax = 0;
	}
	else if (ixRow > 2 && ixRow < 6 && ixCol < 3)
	{
		ymax = 0;
		xmax = 3;
	}
	else if (ixRow > 2 && ixRow < 6 && ixCol < 6 && ixCol > 2)
	{
		ymax = 3;
		xmax = 3;
	}
	else if (ixRow > 2 && ixRow < 6 && ixCol < 9 && ixCol > 5)
	{
		ymax = 6;
		xmax = 3;
	}
	else if (ixRow > 5 && ixRow < 9 && ixCol < 3)
	{
		ymax = 0;
		xmax = 6;
	}
	else if (ixRow > 5 && ixRow < 9 && ixCol < 6 && ixCol > 2)
	{
		ymax = 3;
		xmax = 6;
	}
	else if (ixRow > 5 && ixRow < 9 && ixCol < 9 && ixCol > 5)
	{
		ymax = 6;
		xmax = 6;
	}
	ixRow = xmax;
	ixCol = ymax;
	
	int CurrentIxRow = 0;
	int CurrentIxCol = 0;
	
	for (CurrentIxRow = xmax; CurrentIxRow < xmax+3; CurrentIxRow++)
		for (CurrentIxCol = ymax; CurrentIxCol < ymax+3; CurrentIxCol++)
			square[ CurrentIxRow-xmax ][ CurrentIxCol-ymax ] = GameField[ xmax ][ ymax ];
}
//Проверка значений в квадрате
bool Square3x3::ControlSquare()
{
	for (int ixRow = 0; ixRow < 3; ixRow++)
		for (int ixCol = 0; ixCol < 3; ixCol++)
		{
			if (square[ ixRow ][ ixCol ] == 0)
				return false;
			else return true;
		}
}

Square3x3::~Square3x3(void)
{
}
