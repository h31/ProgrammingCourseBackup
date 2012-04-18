#ifndef _FIELD_H
#define _FIELD_H

#include"Square.h"
//#include <fstream>
//#include <iostream>

using namespace std;

class Field
{
public:
	int** hor;
	int** ver;
	Square** map;
	int height, width;
	Field();
	~Field();
	bool loadField(char* arg);
	bool loadComplete(char* arg);
	bool show();
};

#endif