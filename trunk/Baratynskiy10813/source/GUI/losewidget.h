#ifndef LOSEWIDGET_H
#define LOSEWIDGET_H

#include <QWidget>
#include "QPushButton"
#include "QLabel"
#include "QGridLayout"

class LoseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoseWidget(QWidget *parent = 0);
    QLabel *label1;
    QLabel *label2;
    QPushButton *yes;
    QPushButton *no;
    QGridLayout *layout;
signals:
    
public slots:
    void on_yes_clicked();
};

#endif // LOSEWIDGET_H
