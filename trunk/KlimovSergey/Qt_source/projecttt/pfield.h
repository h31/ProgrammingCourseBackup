#ifndef PFIELD_H
#define PFIELD_H

#include"field.h"
#include"psquare.h"

class Field;

class PField
{
public:
    PField();
    ~PField();
    void paintF(Field& f,QPainter& painter);
    PSquare psq;
};

#endif // PFIELD_H
