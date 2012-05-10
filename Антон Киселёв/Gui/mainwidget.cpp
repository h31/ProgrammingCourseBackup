#include "mainwidget.h"
#include "gameboard.h"
#include "field.h"

MainWidget::MainWidget(int num):QWidget(0)
{
    GameField = new Field(3);
    GameField->Fill_Zero(num);
    FieldButtons = new FieldButton *[ 9 ];
    rows = new QHBoxLayout [ 9 ];
    cols = new QVBoxLayout;
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        FieldButtons[ ixRow ] = new FieldButton [ 9 ];
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            FieldButtons[ ixRow ][ ixCol ].SetIxRowIxCol(ixRow, ixCol, GameField);
            FieldButtons[ ixRow ][ ixCol ].setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
            rows[ ixRow ].addWidget(&(FieldButtons[ ixRow ][ ixCol ]));

            QFont font(QFont("Arials", 16, 0,QFont::Cursive));
            FieldButtons[ ixRow ][ ixCol ].setFont(font);
            QString y(QString::number(FieldButtons[ ixRow ][ ixCol ].chislo,10));
            FieldButtons[ ixRow ][ ixCol ].setText(y);
            QPalette p = FieldButtons[ ixRow ][ ixCol ].palette();
            QColor color;
            color.setRgb(0,100,0,255);
            p.setColor(QPalette::ButtonText,color);
            FieldButtons[ ixRow ][ ixCol ].setPalette(p);
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cols->addLayout(&(rows[ i ]));
    }
    Signals();
    this->setLayout(cols);
    this->resize(500,500);
}

void MainWidget::Signals()
{
    for (int ixRow = 0; ixRow < 9; ixRow++)
        for (int ixCol = 0; ixCol < 9; ixCol++)
            connect(&FieldButtons[ ixRow ][ ixCol ],SIGNAL(clicked()),this,SLOT(check()));
}

MainWidget::~MainWidget()
{
    for (int i = 0; i < 9; i++)
    {
        delete[] FieldButtons[ i ];
    }
    delete[] rows;
    delete[] cols;
    delete[] GameField;
}

void MainWidget::check()
{
    FieldButton* FieldButtons = (FieldButton*)sender();
    int ixRow, ixCol;
    g = new GameBoard;
    g->show();
    FieldButtons->GetIxRowIxCol(ixRow, ixCol);
    FieldButtons->chislo = g->chislo;
    insert_chislo(ixRow, ixCol);
}

void MainWidget::insert_chislo(int ixRow, int ixCol)
{
    QFont font(QFont("Arials", 16, 0,QFont::Cursive));
    FieldButtons[ ixRow ][ ixCol ].setFont(font);
    QString y(QString::number(FieldButtons[ ixRow ][ ixCol ].chislo, 10));
    FieldButtons[ ixRow ][ ixCol ].setText(y);
    QPalette p = FieldButtons[ ixRow ][ ixCol ].palette();
    QColor color;
    color.setRgb(0,100,0,255);
    p.setColor(QPalette::ButtonText,color);
    FieldButtons[ ixRow ][ ixCol ].setPalette(p);
}

void MainWidget::checking_Buttons()
{
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (FieldButtons[ ixRow ][ ixCol ].chislo != GameField->FieldVictory[ ixRow ][ ixCol ])
            {
                QFont font(QFont("Times", 16, 0,QFont::Normal));
                FieldButtons[ ixRow ][ ixCol ].setFont(font);
                QString y(QString::number(GameField->FieldVictory[ ixRow ][ ixCol ],10));
                FieldButtons[ ixRow ][ ixCol ].setText(y);
                QPalette p = FieldButtons[ ixRow ][ ixCol ].palette();
                QColor color;
                color.setRgb(255,0,0,255);
                p.setColor(QPalette::ButtonText,color);
                FieldButtons[ ixRow ][ ixCol ].setPalette(p);
            }
            else
            {
                QFont font(QFont("Times", 16, 0,QFont::Normal));
                FieldButtons[ ixRow ][ ixCol ].setFont(font);
                QString y(QString::number(GameField->FieldVictory[ ixRow ][ ixCol ],10));
                FieldButtons[ ixRow ][ ixCol ].setText(y);
                QPalette p = FieldButtons[ ixRow ][ ixCol ].palette();
                QColor color;
                color.setRgb(0,100,0,255);
                p.setColor(QPalette::ButtonText,color);
                FieldButtons[ ixRow ][ ixCol ].setPalette(p);
            }
        }
    }
}




























