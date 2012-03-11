#include "Cell.h"
#include "Field.h"
Cell::Cell(int ixRow, int ixCol)
{
	cell = GameField[ ixRow ][ ixCol ];
}

Cell::~Cell(void)
{
}
