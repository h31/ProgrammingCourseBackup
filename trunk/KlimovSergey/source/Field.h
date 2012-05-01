#ifndef _FIELD_H
#define _FIELD_H

#include"Square.h"

using namespace std;

class Field
{
public:
	
	Square** map;
	int height, width;
	Field();
	~Field();
	bool loadField(char* arg);
	bool loadComplete(char* arg);
	bool show();
private:
	int** hor;
	int** ver;
	
};

#endif