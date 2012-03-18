
#ifndef _Fruct_h_
#define _Fruct_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

int N=15; //����� �������; ��� ���������� ������� ���������� ������ � �������� ���������� ���� ����������
int Grtime=20;

enum FructTipe { App, Grr };

class Fruct { //��������� �����, ���������� ������� �����
public:
	int x, y;
	Fruct (int X, int Y);
	virtual int show ( )=0;
};

class Apple: public Fruct { //����������� �����
public:
	Apple (int X, int Y);	
	int show();
};
	
class Grusha: public Fruct { //����������� �����
public:
	int time;
	Grusha (int t, int X, int Y);
	int show( );	
};

class Fructs { //������, ��������� �� �������
public:
	Fruct** fruct;
	Fructs (int len);
	void add(); 
};


#endif