#ifndef FIELDBUTTON_H
#define FIELDBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "field.h"

class FieldButton : public QPushButton
{
    
public:
    FieldButton();
    int ixRow, ixCol;
    int chislo;
    void SetIxRowIxCol(int a, int b, Field *GameField);
    void GetIxRowIxCol(int &a, int &b);
    ~FieldButton();

};

#endif // FIELDBUTTON_H
