#ifndef SQUARE_H
#define SQUARE_H

//#include<fstream>
//#include<iostream>
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
    void fill(QPainter& painter);
    void clear(QPainter& painter);
    void mark(QPainter& painter);

private:

    int status;//2-empty;1-painted;0-marked
    //friend ostream& operator <<(ostream& out, const Square& sq);
    //friend istream& operator >>(istream& in, Square& sq);
};

#endif // SQUARE_H
