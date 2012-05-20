#include"field.h"

using namespace std;

Field::Field()
{
    ready=false;
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

 void Field::paint(QPainter &painter)
 {
    painter.fillRect(0,0,sizex,sizey+21,Qt::white);
    QPen pen;
    painter.setPen(Qt::black);
    QString str;
    QFont font;
    font.setPixelSize(sqSize-4);
    painter.setFont(font);
    for(int i=0; i<width; i++)
    {
        for(int j=hcol-1; j>-1; j--)
        {
            if(hor[i][j]!=0)
                painter.drawText((i+vcol)*(sqSize+1)+1,(hcol-1-j)*(sqSize+1)+21+1,sqSize,sqSize,Qt::AlignCenter,str.setNum(hor[i][j]));
        }
    }
    for(int i=vcol-1; i>-1; i--)
    {
        for(int j=0; j<height; j++)
        {
            if(ver[j][i]!=0)
                painter.drawText((vcol-1-i)*(sqSize+1)+1,(j+hcol)*(sqSize+1)+21+1,sqSize,sqSize,Qt::AlignCenter,str.setNum(ver[j][i]));
        }
    }
    for(int i=0;i<width;i++)
        for(int j=0;j<height;j++)
            if(map[i][j].getStat() == 1)
                map[i][j].fill(painter);
            else if(map[i][j].getStat()==2)
                map[i][j].clear(painter);
            else if(map[i][j].getStat()==0)
                map[i][j].mark(painter);
    for(int i = 0;i < (sqSize+1)*(width + vcol)+1;i+=(sqSize+1))
        if((i-vcol*(sqSize+1))%5==0)
        {
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(i,0,i,(sqSize+1)*(height + hcol)+1+21);
            pen.setWidth(1);
            painter.setPen(pen);
        }
        else
            painter.drawLine(i,0,i,(sqSize+1)*(height + hcol)+1+21);
    for(int i = 0;i < (sqSize+1)*(height + hcol)+1+21;i+=(sqSize+1))
        if((i-hcol*(sqSize+1)-21)%5==0)
        {
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(0,i,(sqSize+1)*(width + vcol)+1,i);
            pen.setWidth(1);
            painter.setPen(pen);
        }
        else
            painter.drawLine(0,i,(sqSize+1)*(width + vcol)+1,i);
    painter.fillRect(0,0,(sqSize+1)*vcol,(sqSize+1)*hcol+21,Qt::white);
 }
