#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QtGui>
#include "game.h"
#include "finalresults.h"

class MyDialog: public QDialog
{
    Q_OBJECT

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent * ev);

public:
    MyDialog(QWidget *parent);
    ~MyDialog();
    Game * newGame;
    bool state1;
    bool state2;
};

#endif // MYDIALOG_H
