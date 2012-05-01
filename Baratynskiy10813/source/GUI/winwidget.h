#ifndef WINWIDGET_H
#define WINWIDGET_H

#include <QWidget>
#include "QPushButton"
#include "QLabel"
#include "QGridLayout"

class WinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WinWidget(QWidget *parent = 0);
    QLabel *label1;
    QLabel *label2;
    QPushButton *yes;
    QPushButton *no;
    QGridLayout *layout;
signals:
    
public slots:
    void on_yes_clicked();
};

#endif // WINWIDGET_H
