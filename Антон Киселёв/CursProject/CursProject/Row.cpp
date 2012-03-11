#include "Row.h"
#include "Field.h"
//Выделяем строку
Row::Row(int NumberOfLine)
{
	for(int ixRow = 0; ixRow < width; ixRow++)
		row[ ixRow ] = GameField[ NumberOfLine ][ ixRow ];
}
//Проверка значений в строке
bool Row::ControlRow()
{
	for (int ixCol = 0; ixCol < 9; ixCol++)
	{
		if (row[ ixCol ] == 0)
			return false;
		else return true;
	}
}

Row::~Row(void)
{
}
