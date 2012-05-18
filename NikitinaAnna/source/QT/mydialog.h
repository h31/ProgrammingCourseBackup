#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QtGui>

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent);
    ~MyDialog();
public slots:
    void onMySignal();
};

#endif // MAINWINDOW_H
