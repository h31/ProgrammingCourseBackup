#include "Fruct.h"

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

Fruct::Fruct (int X, int Y) {
        x=X; y=Y;}
Fruct::~Fruct() { }

Apple::Apple (int X, int Y) : Fruct(X,Y) {};
Apple::~Apple () {};
int Apple::fructenumerate ()
{
    return app;
}

Pear::Pear (int t, int X, int Y): Fruct( X,Y) {
        time=t;
    }
Pear::~Pear () {}
int Pear::fructenumerate ( )
{
    return pear;
}
