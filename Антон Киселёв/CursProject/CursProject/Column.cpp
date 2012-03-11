#include "Column.h"
#include "Field.h"
//Выделяем столбец
Column::Column(int NumberOfColumn)
{
	for (int ixCol = 0; ixCol < high; ixCol++)
		column[ ixCol ] = GameField[ ixCol ][ NumberOfColumn ];
}
//Проверка значений в столбце
bool Column::ControlColumn()
{
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		if (column[ ixRow ] == 0)
			return false;
		else return true;
	}
}

Column::~Column(void)
{
}
