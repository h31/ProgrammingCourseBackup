#ifndef FIELD_H
#define FIELD_H

#include"square.h"

using namespace std;

class Field
{
public:
    int sizex,sizey;
    bool ready;
    int height, width, vcol, hcol/*,sqSize*/;

    Field();
    ~Field();
    bool loadField(QString arg);
    bool loadComplete(QString arg);
    //bool show();
    void createEmpty();
    bool Check(QString arg);
    void setSqStat(int st,int x, int y);
    int getSqStat(int x,int y);
    void paint(QPainter& painter);
private:
    int** hor;
    int** ver;
    Square** map;

};

#endif // FIELD_H
