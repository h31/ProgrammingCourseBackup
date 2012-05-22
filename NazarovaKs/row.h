#ifndef _row_h_
#define _row_h_

#include <iostream>
#include <time.h>

using namespace std;

#include <vector>
const int maxColumns=7;

class Exception {};

class Row{
	vector<int> arr;
public:
	Row();	
	int getData(int);
	void setData(int number, int value);
	void clearCell(int a);
	friend ostream& operator << (ostream&, const Row&);
};

#endif