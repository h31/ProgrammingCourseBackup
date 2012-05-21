#include "MainWidget.h"
 #include <QTime>
 #include <QtGui>
 #include <qpalette.h>
 #include <QFont>

MainWidget::MainWidget(int row,int col,int mines):QWidget(0)
 {
    r=row;
    pr=row*col-mines;
    comp=0;
    fields = new TGbutton * [row];
    rows=new QHBoxLayout[row];
    cols=new QVBoxLayout;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    for (int i=0;i<row;i++)
    {
        fields[i]=new TGbutton[col];

      for(int j=0;j<col;j++)
      {
        fields[i][j].setAB(i,j);
        fields[i][j].setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
         rows[i].addWidget(& (fields[i][j]));
         connect(& fields[i][j],SIGNAL(clicked()),this,SLOT(check()));
      }
    }
    for (int i=0;i<row;i++)
         cols->addLayout(& (rows[i]));
         mat=new int *[row];
       for (int i=0;i <row;i++)
       {
         mat[i]=new int[col];
            for (int j=0;j<col;j++)
              mat[i][j]=0;
       }
       this->setLayout(cols);
    for (int i=0;i<mines;)
    {
    int e=qrand()%(row-1);
    int q=qrand()%(col-1);
    if(mat[e][q]!=-1)
    {
    mat[e][q]=-1;
    i++;
    }
    }
    for(int i=0;i<row;i++)
        for (int j=0;j<col;j++)
    {
    if(mat[i][j]==-1)
    {
    if((i-1)>=0)
    {
    if(mat[i-1][j]!=-1)mat[i-1][j]++;

    if((j+1)<col)
    if(mat[i-1][j+1]!=-1)
    mat[i-1][j+1]++;

    if((j-1)>=0)
    if(mat[i-1][j-1]!=-1)
    mat[i-1][j-1]++;
    }

    if((i+1)<row)
    {
    if(mat[i+1][j]!=-1)
    mat[i+1][j]++;

    if(j+1<col)
    if(mat[i+1][j+1]!=-1)
    mat[i+1][j+1]++;

    if(j-1>=0)
    if(mat[i+1][j-1]!=-1)
    mat[i+1][j-1]++;
    }
    if((j+1)<col)
    if(mat[i][j+1]!=-1)
    mat[i][j+1]++;

    if((j-1)>=0)
    if(mat[i][j-1]!=-1)
    mat[i][j-1]++;
    }
    }
    this->resize(500,500);
    }


void MainWidget::check()
 {
    TGbutton *button=(TGbutton*)sender();
     int a,b;
     button->GetAB(a,b);
     QFont font("Sans",16,16,false);

      button->setFont(font);

      QString y(QString::number(mat[a][b],10));
       button->setText(y);

       button->setEnabled(false);
        QPalette p=button->palette();
        QColor color;

        if(mat[a][b]==-1)
        {
            emit boom();
            return;
        }
         if(mat[a][b]==1)
             color.setRgb(50,205,80,255);
         else if(mat[a][b]==2)
             color.setRgb(220,160,40,255);
         else if(mat[a][b]==0)
             color.setRgb(0,0,0,255);

         else
             color.setRgb(255,0,0,255);

         p.setColor(QPalette::ButtonText,color);
         button->setPalette(p);
         comp++;
         if(comp==pr)emit finish();
          emit progress((int)(((float)comp/(float)pr)*100));
    }


MainWidget::~MainWidget()
 {
   for (int i=0;i<r;i++)
   {
     delete [] mat[i];
       delete [] fields[i];
   }
 delete[] mat;
 delete[] fields;
 delete[] rows;
 delete cols;
 }

