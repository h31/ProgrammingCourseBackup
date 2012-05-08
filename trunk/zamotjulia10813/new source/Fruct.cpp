#include "stdafx.h"
#include "Fruct.h"
#include "stdafx.h"

int Fruct::getx() {return x;}
bool Fruct::setx (int new_x)
{	x=new_x;
    return true;
}
int Fruct::gety() {return y;}
bool Fruct::sety (int new_y)
{	y=new_y;
    return true;
}
bool Fruct::settype(int newtype)
{
	if(newtype == app || newtype== pear)
	{
		type=newtype;
		return true;
	}
	else
	{
		return false;
	}
}
int Fruct::gettype ( )
{
    return type;
}
Fruct::Fruct (int X, int Y) 
{
        x=X; 
		y=Y;
}

Fruct::Fruct()
{
	x=0;
	y=0;
}

Fruct::~Fruct() { }

Apple::Apple (int X, int Y) : Fruct(X,Y) 
{
	settype(app);
};
Apple::~Apple () {};

Pear::Pear (int t, int X, int Y): Fruct( X,Y) 
{
	settype(pear);
	time=t;
}
Pear::~Pear () {}

int Pear::gettime()
{
	return this->time;
}
bool Pear::settime(int newtime)
{
	if(newtime>0)
	{
		this->time=newtime;
		return true;
	}
	else
	{
		return false;
	}
}


