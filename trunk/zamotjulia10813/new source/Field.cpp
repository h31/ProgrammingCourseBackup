#include "Field.h"

Field::Field (int W, int H)
{
    w=W; h=H;
    createField();
};
Field:: ~Field ()
{
    for (int i=0; i<h; i++)
        delete p[i];
    delete [] p;
}

bool Field::createField()
{
    p= new int *[h];

        for (int i=0; i<h; i++)
        {
            p[i]= new int[w];
        }
        return true;
};

void Field::init() {

        //началный вывод, там где ничего нет - будут 8
        for (int i=0; i<h; i++)
             for (int g=0; g<w; g++)
                 p[i][g]=8;
    };

void Field::show() {
            // вывод массива поля
                for (int i=0; i<h; i++)
                {
                    for (int g=0; g<w; g++)
                    cout<<intToChar(p[i][g]);
                    cout<<endl;
                }
};

char Field::intToChar (int Code)
{
    switch(Code)
    {
    case App:
        return 'a';
        break;
    case Grr:
        return 'g';
        break;
    case Snakehead:
        return '@';
        break;
    case Snaketail:
        return '#';
        break;
    case 8:
        return '_';
        break;
    default:
        return '_';
        break;
    }
}

bool Field::setp (int x, int y, int new_value)
{ p[x][y] = new_value;
return true;
}

int Field::getp (int x, int y) {
    return p[x][y];}





