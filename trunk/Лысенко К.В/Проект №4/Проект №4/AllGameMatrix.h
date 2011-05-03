#ifndef AllGameMatrix_h
#define AllGameMatrix_h

#include<vector>
#include<iostream>
using namespace std;

class AllGameMatrix
{
	vector<vector<int>> matr;
public:
	bool isright();
	bool issquare();
	void add(int val, int nstr);
	int numstr();
	const vector<int> &operator[](int ix);
	void clear();
	void print_str(int nstr, ostream &out);
};

#endif