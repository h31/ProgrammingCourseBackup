#include"field.h"

using namespace std;

Field::Field()
{
    ready=false;
    //sqSize =20;
}

Field::~Field()
{}

bool Field::loadField(QString arg)
{
    QFile file(arg);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    in>>width
      >>height
      >>hcol
      >>vcol;
    int **hortmp = new int*[width];
    for(int i=0;i<width;i++)
        hortmp[i] = new int [hcol];
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<hcol; j++)
        {
               in>>hortmp[i][j];
        }
    }
    hor = hortmp;
    int **vertmp = new int*[height];
    for(int i=0;i<height;i++)
        vertmp[i] = new int [vcol];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<vcol; j++)
        {
               in>>vertmp[i][j];
        }
    }
    ver = vertmp;
    sizex = (sqSize+1)*(width + vcol)+1;
    sizey = (sqSize+1)*(height + hcol)+1;
    file.close();
    ready = true;
    return true;
}

bool Field::loadComplete(QString arg)
{
    QFile file(arg);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in1(&file);
        in1>>width>>height;
        int temp;
        Square **tmp = new Square*[width];
        for(int i=0;i<width;i++)
            tmp[i] = new Square [height];
        for(int j=0;j<height;j++)
            {
                for(int i=0;i<width;i++)
                {
                    in1 >> temp;
                    tmp[i][j].setStat(temp);
                    tmp[i][j].s.x = (i+vcol)*(sqSize+1)+1;
                    tmp[i][j].s.y = (j+hcol)*(sqSize+1)+1;
                }
            }
        map = tmp;
        return true;
}


void Field::createEmpty()
 {
    Square **tmp = new Square*[width];
    for(int i=0;i<width;i++)
        tmp[i] = new Square [height];
    for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                tmp[i][j].setStat(2);
                tmp[i][j].s.x = (i+vcol)*(sqSize+1)+1;
                tmp[i][j].s.y = (j+hcol)*(sqSize+1)+1;
            }
        }
    sizex = (sqSize+1)*(width + vcol)+1;
    sizey = (sqSize+1)*(height + hcol)+1;
    map = tmp;
 }
 bool Field::Check(QString arg)
{
    Field test;
    test.loadComplete(arg);
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(map[i][j].getStat()==0)
                map[i][j].setStat(2);
        }
    }
    for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                if(test.map[i][j].getStat() == map[i][j].getStat())
                    continue;
                else
                    return false;
            }
        }
    return true;
}

 void Field::setSqStat(int st,int x, int y)
 {
     map[x][y].setStat(st);
 }

 int Field::getSqStat(int x,int y)
 {
     return map[x][y].getStat();
 }
