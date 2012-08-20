#include "russtat.h"
#include "ui_russtat.h"

RusStat::RusStat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RusStat)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
}

RusStat::~RusStat()
{
    delete ui;
}

QLabel* RusStat::returnGames()
{
    return ui->dgames;
}

QLabel* RusStat::returnWins()
{
    return ui->dwins;
}


QLabel* RusStat::returnLoses()
{
    return ui->dloses;
}

QLabel* RusStat::returnWinPercent()
{
    return ui->winpercent;
}


QLabel* RusStat::returnLosePercent()
{
    return ui->losepercent;
}
