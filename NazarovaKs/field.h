#ifndef _field_h_
#define _field_h_

#include "cell.h"

#include <vector>

class Field:private Cell{
	int rows;
public:
	Field();
	Field(int a);
	~Field();

	vector<Cell>field;
	void deleteCell(int, int, int, int);
	void addCells();
	friend ostream& operator << (ostream& out, const Field&);
};

#endif