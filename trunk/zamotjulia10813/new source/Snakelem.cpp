#include "Snakelem.h"

ZmElement::ZmElement (int X, int Y) {x=X; y=Y;};
ZmElement::ZmElement() {};

ZmElement::~ZmElement() {};

int ZmElement::getx() {return x;};
int ZmElement::gety() {return y;};

bool ZmElement::setx (int new_x) {
    if (new_x<0) return false;
    else
    {
        x=new_x;
        return true;
    }
};
bool ZmElement::sety (int new_y) {
    if (new_y<0) return false;
    else
    {
        x=new_y;
        return true;
    }

};
