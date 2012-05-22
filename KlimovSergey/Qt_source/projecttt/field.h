#ifndef FIELD_H
#define FIELD_H

#include"square.h"
#include"pfield.h"

using namespace std;

class Field
{
public:
    int sizex,sizey;
    bool ready;
    int height, width, vcol, hcol;

    Field();
    ~Field();
    bool loadField(QString arg);
    bool loadComplete(QString arg);
    void createEmpty();
    bool Check(QString arg);
    void setSqStat(int st,int x, int y);
    int getSqStat(int x,int y);
    friend class PField;
private:
    int** hor;
    int** ver;
    Square** map;

};

#endif // FIELD_H
