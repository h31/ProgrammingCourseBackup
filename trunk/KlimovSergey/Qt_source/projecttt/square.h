#ifndef SQUARE_H
#define SQUARE_H

#include<QtGui>

using namespace std;

const int sqSize = 20;

struct Point
{
    int x,y;
};

class Square
{
public:
    Point s;
    int getStat();
    void setStat(int st);
    Square();
    ~Square();
    friend class PSquare;
private:

    int status;//2-empty;1-painted;0-marked
};

#endif // SQUARE_H
