#ifndef _SQUARE_H
#define _SQUARE_H

#include<fstream>
#include<iostream>

using namespace std;

struct Point
{
	int x,y;
};

class Square
{
public:
	Point s;
	int status;//0-empty;1-painted;2-marked
	int getStat();
	Square();
	~Square();
	friend ostream& operator <<(ostream& out, const Square& sq);
	friend istream& operator >>(istream& in, Square& sq);
};

#endif