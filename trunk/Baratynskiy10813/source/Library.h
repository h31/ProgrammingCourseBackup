#ifndef LIBRARY_H
#define LIBRARY_H
#include <fstream>
#include "Man.h"
#include "Word.h"
#include <time.h>

class Library
{
	int randNum;
	int var;
public:
	string takeWord();
	int chooseTheme();
};

#endif