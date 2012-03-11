#pragma once
#include "Field.h"
class Row: public Field
{
	static const int width= 9;
public:
	int row[ width ];
	int NumberOfRow;

	Row(int NumberOfLine);
	bool ControlRow();
	~Row(void);
};
