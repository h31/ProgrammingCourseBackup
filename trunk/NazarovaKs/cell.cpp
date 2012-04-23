#include "cell.h"

Cell::Cell(): x(0), y(0), data(0) {}

Cell::Cell(unsigned a, unsigned b): x(a), y(b) {}

Cell::~Cell() {}

ostream& operator << (ostream& out, const Cell& cell)
{
	out<<cell.data;
	return out;
}

void Cell::createCell()
{
	data=1+rand()%9;
}