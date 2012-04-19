#ifndef _FIELD_H
#define _FIELD_H

#include"Square.h"

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