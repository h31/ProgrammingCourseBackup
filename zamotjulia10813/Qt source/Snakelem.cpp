#include "Snakelem.h"

ZmElement::ZmElement (int X, int Y) {x=X; y=Y;};
ZmElement::ZmElement() {}

ZmElement::~ZmElement() {};

int ZmElement::getx() {return x;}
int ZmElement::gety() {return y;}

bool ZmElement::setx (int new_x) {
        x=new_x;
        return true;
}
bool ZmElement::sety (int new_y) {
        x=new_y;
        return true;
}

int ZmElement::getnapx() {return napx;};
int ZmElement::getnapy() {return napy;};

bool ZmElement::set_napx(int new_napx) {
    napx=new_napx;
    return true;
}
bool ZmElement::set_napy(int new_napy) {
    napy=new_napy;
    return true;
}
