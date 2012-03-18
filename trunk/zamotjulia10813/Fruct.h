
#ifndef _Fruct_h_
#define _Fruct_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

int N=15; //число фруктов; при компил€ции выходит непон€тна€ ошибка с областью объ€влени€ этих переменных
int Grtime=20;

enum FructTipe { App, Grr };

class Fruct { //единичный фрукт, абстрактый базовый класс
public:
	int x, y;
	Fruct (int X, int Y);
	virtual int show ( )=0;
};

class Apple: public Fruct { //производный класс
public:
	Apple (int X, int Y);	
	int show();
};
	
class Grusha: public Fruct { //производный класс
public:
	int time;
	Grusha (int t, int X, int Y);
	int show( );	
};

class Fructs { //‘рукты, состо€щие из фруктов
public:
	Fruct** fruct;
	Fructs (int len);
	void add(); 
};


#endif