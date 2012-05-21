#ifndef _check_h_
#define _check_h_

#include "field.h"

class Check{
	Field f;
	bool checkSameValues(int, int, int, int);
	bool checkSumValues(int, int, int, int);
	bool checkPlace(int, int, int, int);
	bool nullValue(int, int, int, int);
public:
	Check();
	Check(Field&);
	bool checkMove(int, int, int, int);
};

#endif