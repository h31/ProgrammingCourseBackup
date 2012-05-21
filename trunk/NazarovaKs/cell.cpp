#include "cell.h"

Cell::Cell(){	
	for(int i=0; i<maxColumns; i++)
		arr[i]=1+rand()%9;
}

Cell::~Cell() {}

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