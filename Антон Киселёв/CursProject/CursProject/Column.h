#pragma once
#include "Field.h"
class Column: public Field
{
	static const int high = 9;
public:
	int column[ high ];
	int NumberOfColumn;

	Column(int NumberOfColumn);
	bool ControlColumn();
	~Column(void);
};
