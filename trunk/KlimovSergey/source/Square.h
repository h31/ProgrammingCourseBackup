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
	//bool painted, marked, empty;
	int status;
	int getStat();
	Square();
	~Square();
	//friend ifstream& operator >>(ifstream& in, Square& sq);
	friend ostream& operator <<(ostream& out, const Square& sq);
	friend istream& operator >>(istream& in, Square& sq);
};

#endif