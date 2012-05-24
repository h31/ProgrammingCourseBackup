#ifndef _row_h_
#define _row_h_

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

const int maxColumns=2;
const int maxRows=49;

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
