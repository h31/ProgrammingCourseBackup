#include "fieldbutton.h"
#include "field.h"

FieldButton::FieldButton():QPushButton()
{
}

FieldButton::~FieldButton()
{
}

void FieldButton::SetIxRowIxCol(int a, int b, Field *GameField)
{
    ixRow = a;
    ixCol = b;
    chislo = GameField->GameField[ a ][ b ];
}

void FieldButton::GetIxRowIxCol(int &a, int &b)
{
    a = ixRow;
    b = ixCol;
}
