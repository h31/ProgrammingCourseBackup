#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "Game.h"
#include "dealer_cards.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void printFirstDispensation();
    QPainter pen;
    Game *game;
    RealPlayer *rpl;
    Dealer *dlr;
private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector <QImage> cardss;
    QImage im;
    /*enum cards {two_hearts,three_hearts,four_hearts,five_hearts,six_hearts,seven_hearts,eight_hearts,nine_hearts,ten_hearts,jack_hearts,queen_hearts,king_hearts,ace_hearts,
                two_diamonds,three_diamonds,four_diamonds,five_diamonds,six_diamonds,seven_diamonds,eight_diamonds,nine_diamonds,ten_diamonds,jack_diamonds,queen_diamonds,king_diamonds,ace_diamonds,
                two_spades, three_spades, four_spades, five_spades,six_spades, seven_spades,eight_spades, nine_spades, ten_spades,jack_spades,queen_spades,king_spades,ace_spades,
                two_clubs,three_clubs,four_clubs, five_clubs,six_clubs,seven_clubs,eigth_clubs,nine_clubs,ten_clubs,jack_clubs,queen_clubs,king_clubs,ace_clubs
               }*/

    enum cardss
    {
    T,
    D
    };
};

#endif // MAINWINDOW_H
