#ifndef _FIELD_H
#define _FIELD_H

#include"Square.h"

using namespace std;

class Field
{
public:
	
	
	int height, width;
	Field();
	~Field();
	bool loadField(char* arg);
	bool loadComplete(char* arg);
	bool show();
	void setSqStat(int st,int x, int y);
    int getSqStat(int x,int y);
	void createEmpty();
private:
	int** hor;
	int** ver;
	Square** map;
};

#endif