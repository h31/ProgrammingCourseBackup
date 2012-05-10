#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <fieldbutton.h>
#include <QLayout>
#include "field.h"
#include "gameboard.h"

class MainWidget : public QWidget
{
    Q_OBJECT
    
private:
    QHBoxLayout *rows;
    QVBoxLayout *cols;
public:
    MainWidget(int num);
    FieldButton **FieldButtons;
    GameBoard *g;
    Field *GameField;
    void checking_Buttons();
    void insert_chislo(int ixRow, int ixCol);
    void Signals();
    ~MainWidget();
public slots:
    void check();
signals:
};

#endif // MAINWIDGET_H
