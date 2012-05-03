#ifndef RUSSIANWIDGET_H
#define RUSSIANWIDGET_H

#include <QWidget>
#include "QPushButton"
#include "QLabel"
#include "QGridLayout"
#include "Game.h"
#include "QPainter"
#include "QPaintEvent"
#include "ruslosewidget.h"
#include "ruswinwidget.h"

namespace Ui {
class RussianWidget;
}

class RussianWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit RussianWidget(QWidget *parent = 0);
    ~RussianWidget();
    Game *game;
    RusLoseWidget *iflose;
    RusWinWidget *ifwin;
    void connectButtons();
    void makeLabel();
    void addWidgets(QGridLayout *layout);
    void checkLetter();
public:
    void play();
protected:
    void paintEvent(QPaintEvent *event);
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_25_clicked();

private:
    Ui::RussianWidget *ui;
};

#endif // RUSSIANWIDGET_H
