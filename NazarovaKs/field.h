#ifndef _field_h_
#define _field_h_

#include <iostream>
#include <fstream>

using namespace std;

class Exception {};

class Cell
{
public:
	int cx, cy;
	Cell();
	Cell(int px, int py);
	~Cell();

	friend ostream& operator << (ostream& out, const Field&f); // Ошибка, но не понимаю, что здесь еще требуется указать
};

class Field:Cell
{
	
public:	
	Cell **cells;
	int fx, fy;

	Field();
	Field(int xsize, int ysize);
	~Field();

	void createField();
	void print(Field& f);

	
};


#endif