#pragma once
#include "Field.h"
class Cell: public Field
{
	int cell;
public:
	Cell(int ixRow, int ixCol);
	~Cell(void);
};
