#ifndef _Field_h_
#define _Field_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Fructs.h"
#include "Snake.h"

class Field {
private:
    int** p;
    char intToChar (int Code); //��������� ������� ��� ����.��������� ����
public:
    int w,h;
public:
    Field (int W, int H);
    Field ();
    ~Field ();
    bool setp (int x, int y, int new_value); //��� ��������� ������� ����
    int getp (int x, int y); //�������� ������
    bool createField ();
    void init ();
    void show ();


};

#endif
