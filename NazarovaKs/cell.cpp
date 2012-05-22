#include "cell.h"

Cell::Cell(){
	arr.resize(maxColumns);
	for(int i=0; i<maxColumns; i++)
		arr[i]=1+rand()%9;
}

ostream& operator << (ostream& out, const Cell& cell){	
	for (int i=0; i<maxColumns; i++)
		out<<cell.arr[i]<<" ";
	out<<endl;
	return out;
}

int Cell::getData(int a){
	if (a<=maxColumns)
		return arr[a];
	else throw Exception();
}

void Cell::clearCell(int a)
{
	if (a<=maxColumns)
		arr[--a]=0;
	else throw Exception();
}

void Cell::setData(int number, int value)
{
	if (number<=maxColumns)
		arr[number] = value;
	else throw Exception();
}