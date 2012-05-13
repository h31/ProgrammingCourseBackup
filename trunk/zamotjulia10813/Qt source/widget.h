#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include "mydialog.h"
#include "scoredialog.h"
#include "aboutdialog.h"

class Widget : public QWidget
{
    Q_OBJECT

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
public:
    MyDialog* Gdialog;
    ScoreDialog* Sdialog;
    AboutDialog* Abdialog;
public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void onShowGameDialog();
    void onShowScoreDialog();
    void onShowAboutDialog();
};

#endif // WIDGET_H
