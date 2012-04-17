#pragma once
#include "Field.h"
class Cell
{
	int number;
public:
	Cell(Field GameField, int ixRow, int ixCol){number = GameField.GameField[ ixRow ][ ixCol ];}
	void GetCell();
	~Cell(void);
};
