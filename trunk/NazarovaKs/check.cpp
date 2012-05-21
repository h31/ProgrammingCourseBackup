#include "check.h"

Check::Check() {}

Check::Check(Field&field){
	f=field;
}

bool Check::checkMove(int a1, int b1, int a2, int b2){
	if ((checkSameValues(a1, b1, a2, b2) || checkSumValues(a1, b1, a2, b2)) && checkPlace(a1, b1, a2, b2) && nullValue(a1, b1, a2, b2))
		return true;
	else return false;
}

bool Check::checkSameValues(int a1, int b1, int a2, int b2){
	if (f.field[--a1].getData(--b1)==f.field[--a2].getData(--b2))
		return true;	
	else return false;
}

bool Check::checkSumValues(int a1, int b1, int a2, int b2){
	if (f.field[--a1].getData(--b1)+f.field[--a2].getData(--b2)==10)
		return true;
	else return false;
}

bool Check::checkPlace(int a1, int b1, int a2, int b2){
	return true;
}

bool Check::nullValue(int a1, int b1, int a2, int b2){
	if (f.field[--a1].getData(--b1)==0 || f.field[--a2].getData(--b2)==0)
		return false;
	else return true;
}