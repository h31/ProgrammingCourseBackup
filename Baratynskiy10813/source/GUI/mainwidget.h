#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "QPushButton"
#include "QLabel"
#include "QGridLayout"
#include "Game.h"
#include "QPainter"
#include "QPaintEvent"
#include "iflosewidget.h"
#include "ifwinwidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    Game *game;
    IfLoseWidget *iflose;
    IfWinWidget *ifwin;
    void connectButtons();
    void makeLabel();
    void addWidgets(QGridLayout *layout);
    void checkLetter();
public:
    void play();
protected:
    void paintEvent(QPaintEvent *event);
    
private slots:
    void on_a_clicked();

    void on_b_clicked();

    void on_c_clicked();

    void on_d_clicked();

    void on_e_clicked();

    void on_f_clicked();

    void on_g_clicked();

    void on_h_clicked();

    void on_i_clicked();

    void on_j_clicked();

    void on_k_clicked();

    void on_l_clicked();

    void on_m_clicked();

    void on_n_clicked();

    void on_o_clicked();

    void on_p_clicked();

    void on_q_clicked();

    void on_r_clicked();

    void on_s_clicked();

    void on_t_clicked();

    void on_u_clicked();

    void on_v_clicked();

    void on_w_clicked();

    void on_x_clicked();

    void on_y_clicked();

    void on_z_clicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
