#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QLabel>


class GameBoard : public QWidget
{
    Q_OBJECT
    QPushButton *button_1, *button_2, *button_3, *button_4, *button_5, *button_6, *button_7, *button_8, *button_9, *button_10;
    QHBoxLayout *lay;
public:
    GameBoard();
    int chislo;
    void Signals();
    int ReturnChislo();
    ~GameBoard();

public slots:
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
};

#endif // GAMEBOARD_H
