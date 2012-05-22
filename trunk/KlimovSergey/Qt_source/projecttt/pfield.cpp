#include "pfield.h"

PField::PField()
{
}

PField::~PField()
{
}

void PField::paintF(Field& f,QPainter &painter)
 {
    painter.fillRect(0,0,f.sizex,f.sizey+21,Qt::white);
    QPen pen;
    painter.setPen(Qt::black);
    QString str;
    QFont font;
    font.setPixelSize(sqSize-4);
    painter.setFont(font);
    for(int i=0; i<f.width; i++)
    {
        for(int j=f.hcol-1; j>-1; j--)
        {
            if(f.hor[i][j]!=0)
                painter.drawText((i+f.vcol)*(sqSize+1)+1,(f.hcol-1-j)*(sqSize+1)+21+1,sqSize,sqSize,Qt::AlignCenter,str.setNum(f.hor[i][j]));
        }
    }
    for(int i=f.vcol-1; i>-1; i--)
    {
        for(int j=0; j<f.height; j++)
        {
            if(f.ver[j][i]!=0)
                painter.drawText((f.vcol-1-i)*(sqSize+1)+1,(j+f.hcol)*(sqSize+1)+21+1,sqSize,sqSize,Qt::AlignCenter,str.setNum(f.ver[j][i]));
        }
    }
    for(int i=0;i<f.width;i++)
        for(int j=0;j<f.height;j++)
            psq.draw(f.map[i][j],painter);

    for(int i = 0;i < (sqSize+1)*(f.width + f.vcol)+1;i+=(sqSize+1))
        if((i-f.vcol*(sqSize+1))%5==0)
        {
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(i,0,i,(sqSize+1)*(f.height + f.hcol)+1+21);
            pen.setWidth(1);
            painter.setPen(pen);
        }
        else
            painter.drawLine(i,0,i,(sqSize+1)*(f.height + f.hcol)+1+21);
    for(int i = 0;i < (sqSize+1)*(f.height + f.hcol)+1+21;i+=(sqSize+1))
        if((i-f.hcol*(sqSize+1)-21)%5==0)
        {
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawLine(0,i,(sqSize+1)*(f.width + f.vcol)+1,i);
            pen.setWidth(1);
            painter.setPen(pen);
        }
        else
            painter.drawLine(0,i,(sqSize+1)*(f.width + f.vcol)+1,i);
    painter.fillRect(0,0,(sqSize+1)*f.vcol,(sqSize+1)*f.hcol+21,Qt::white);
 }
