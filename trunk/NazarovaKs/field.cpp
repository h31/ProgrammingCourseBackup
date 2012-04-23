#include "field.h"

Field::Field(): rows(7), columns(8) 
{
	cells=new Cell *[columns];
	for (unsigned i=0; i<columns; i++)
		cells[i]=new Cell[rows];	
}

Field::Field(unsigned a, unsigned b): rows(a), columns(b) 
{
	cells=new Cell *[columns];
	for (unsigned i=0; i<columns; i++)
		cells[i]=new Cell[rows];
}
	
Field::~Field() {}

ostream& operator << (ostream& out, const Field& field)
{
	for (unsigned i=0; i<field.rows; i++)
	{
		for(unsigned j=0; j<field.columns; j++)
			out<<field.cells[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return out;
}

void Field::createField()
{
	for (unsigned i=0; i<rows; i++)
		for (unsigned j=0; j<columns; j++)
			cells[i][j].createCell();
}

