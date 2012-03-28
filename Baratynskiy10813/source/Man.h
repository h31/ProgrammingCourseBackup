#ifndef MAN_H
#define MAN_H
#include <iostream>
using namespace std;
class Man
{
	void createMan();
	void drawMan();
public:
	char man[6];
	int maxMisses;
	int curMisses;
	Man();
	void makeMan();
};
#endif