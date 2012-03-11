#pragma once
#include "Field.h"
class Square3x3: public Field
{
public:
	int square[ 3 ][ 3 ];

	Square3x3(int ixRow, int ixCol);
	bool ControlSquare();
	~Square3x3(void);
};
