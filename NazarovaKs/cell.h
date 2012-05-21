#ifndef _cell_h_
#define _cell_h_

#include <iostream>
#include <time.h>

using namespace std;

const int maxColumns=7;

class Exception {};

class Cell{
	
public:
	int arr[maxColumns];
	Cell();
	~Cell();	
	int getData(int);
	friend ostream& operator << (ostream&, const Cell&);
};

#endif