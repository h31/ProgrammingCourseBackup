#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
}

Stats::~Stats()
{
    delete ui;
}

QLabel* Stats::returnGames()
{
    return ui->dgames;
}

QLabel* Stats::returnWins()
{
    return ui->dwins;
}


QLabel* Stats::returnLoses()
{
    return ui->dloses;
}

QLabel* Stats::returnWinPercent()
{
    return ui->winpercent;
}


QLabel* Stats::returnLosePercent()
{
    return ui->losepercent;
}
