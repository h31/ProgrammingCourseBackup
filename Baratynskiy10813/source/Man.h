#ifndef MAN_H
#define MAN_H
#include <iostream>
using namespace std;
class Man
{
public:
	char man[6];
	int maxMisses;
	int curMisses;
	Man();
	void createMan();
	void drawMan();
};
#endif