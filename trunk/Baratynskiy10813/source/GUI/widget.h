#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPushButton"
#include "QLabel"
#include "QGridLayout"
#include "Game.h"
#include "winwidget.h"
#include "losewidget.h"
#include "QPainter"
#include "QPaintEvent"
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
private:
    QPushButton *a;
    QPushButton *b;
    QPushButton *c;
    QPushButton *d;
    QPushButton *e;
    QPushButton *f;
    QPushButton *g;
    QPushButton *h;
    QPushButton *i;
    QPushButton *j;
    QPushButton *k;
    QPushButton *l;
    QPushButton *m;
    QPushButton *n;
    QPushButton *o;
    QPushButton *p;
    QPushButton *q;
    QPushButton *r;
    QPushButton *s;
    QPushButton *t;
    QPushButton *u;
    QPushButton *v;
    QPushButton *w;
    QPushButton *x;
    QPushButton *y;
    QPushButton *z;
    QLabel *label;
    QLabel *miss;
    Game *game;
    WinWidget *win;
    LoseWidget *lose;
    void connectButtons();
    void makeLabel();
    void addWidgets(QGridLayout *layout);
    void checkLetter();
public:
    void play();
protected:
    void paintEvent(QPaintEvent *event);
signals:
    
private slots:
    void on_A_clicked();
    void on_B_clicked();
    void on_C_clicked();
    void on_D_clicked();
    void on_E_clicked();
    void on_F_clicked();
    void on_G_clicked();
    void on_H_clicked();
    void on_I_clicked();
    void on_J_clicked();
    void on_K_clicked();
    void on_L_clicked();
    void on_M_clicked();
    void on_N_clicked();
    void on_O_clicked();
    void on_P_clicked();
    void on_Q_clicked();
    void on_R_clicked();
    void on_S_clicked();
    void on_T_clicked();
    void on_U_clicked();
    void on_V_clicked();
    void on_W_clicked();
    void on_X_clicked();
    void on_Y_clicked();
    void on_Z_clicked();
};

#endif // WIDGET_H
