#ifndef _cell_h_
#define _cell_h_

#include <iostream>
#include <time.h>

using namespace std;

#include <vector>
const int maxColumns=7;

class Exception {};

class Cell{
	vector<int> arr;
public:
	Cell();	
	int getData(int);
	void setData(int number, int value);
	void clearCell(int a);
	friend ostream& operator << (ostream&, const Cell&);
};

#endif