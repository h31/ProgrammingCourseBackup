#ifndef _field_h_
#define _field_h_

#include "row.h"
#include <vector>

class Field{
	int rows;
public:
	Field();
	Field(int a);
	~Field();

	vector<Row>field;
    bool deleteCell(int, int, int, int);
	void deleteEmptyRow();
	void addCells();
	friend ostream& operator << (ostream& out, const Field&);
    friend class Test;
};

#endif
