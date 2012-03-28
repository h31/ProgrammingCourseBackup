#ifndef USERWORD_H
#define USERWORD_H
#include <iostream>
#include <string>
#include "BasicWord.h"
using namespace std;
class UserWord : public BasicWord
{
public:
	UserWord();
	void enterWord();
};
#endif