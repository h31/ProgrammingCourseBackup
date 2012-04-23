#ifndef _field_h_
#define _field_h_

#include "cell.h"

class Field
{
	unsigned columns, rows;
public:
	Cell **cells;
	Field();
	Field(unsigned, unsigned);
	~Field();

	void createField();
	
	friend ostream& operator << (ostream& , const Field& );
};

#endif