#ifndef _cell_h_
#define _cell_h_

#include <iostream>
using namespace std;

class Cell
{
	unsigned x, y;
	unsigned data;
public:
	Cell();
	Cell(unsigned ,unsigned );
	~Cell();

	void createCell();

	friend ostream& operator << (ostream& , const Cell& );
};

#endif