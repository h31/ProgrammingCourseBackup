#include "Fruct.h"

Fruct::Fruct (int X, int Y) {
        x=X; y=Y;};

Fruct::~Fruct(){}

Apple::Apple (int X, int Y) : Fruct(X,Y) {};
Apple::~Apple () {};

int Apple::enumfunc ()
{
    return App;
};

Grusha::Grusha (int t, int X, int Y): Fruct( X,Y) {
        time=t;
    }
Grusha::~Grusha () {};

int Grusha::enumfunc ( )
{
    return Grr;
};
