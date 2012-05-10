#include "gameboard.h"
#include "mainwindow.h"
GameBoard::GameBoard()
{
    lay = new QHBoxLayout;
    button_1 = new QPushButton("&1");
    button_2 = new QPushButton("&2");
    button_3 = new QPushButton("&3");
    button_4 = new QPushButton("&4");
    button_5 = new QPushButton("&5");
    button_6 = new QPushButton("&6");
    button_7 = new QPushButton("&7");
    button_8 = new QPushButton("&8");
    button_9 = new QPushButton("&9");
    lay->addWidget(button_1);
    lay->addWidget(button_2);
    lay->addWidget(button_3);
    lay->addWidget(button_4);
    lay->addWidget(button_5);
    lay->addWidget(button_6);
    lay->addWidget(button_7);
    lay->addWidget(button_8);
    lay->addWidget(button_9);
    this->setLayout(lay);
}

void GameBoard::Signals()
{
    connect(button_1,SIGNAL(clicked()),SLOT(on_button_1_clicked()));
    connect(button_2,SIGNAL(clicked()),SLOT(on_button_2_clicked()));
    connect(button_3,SIGNAL(clicked()),SLOT(on_button_3_clicked()));
    connect(button_4,SIGNAL(clicked()),SLOT(on_button_4_clicked()));
    connect(button_5,SIGNAL(clicked()),SLOT(on_button_5_clicked()));
    connect(button_6,SIGNAL(clicked()),SLOT(on_button_6_clicked()));
    connect(button_7,SIGNAL(clicked()),SLOT(on_button_7_clicked()));
    connect(button_8,SIGNAL(clicked()),SLOT(on_button_8_clicked()));
    connect(button_9,SIGNAL(clicked()),SLOT(on_button_9_clicked()));
}

void GameBoard::on_button_1_clicked()
{
    chislo = 1;
}

void GameBoard::on_button_2_clicked()
{
    chislo = 2;
}

void GameBoard::on_button_3_clicked()
{
    chislo = 3;
}

void GameBoard::on_button_4_clicked()
{
    chislo = 4;
}

void GameBoard::on_button_5_clicked()
{
    chislo = 5;
}

void GameBoard::on_button_6_clicked()
{
    chislo = 6;
}

void GameBoard::on_button_7_clicked()
{
    chislo = 7;
}

void GameBoard::on_button_8_clicked()
{
    chislo = 8;
}

void GameBoard::on_button_9_clicked()
{
    chislo = 9;
}

int GameBoard::ReturnChislo()
{
    return chislo;
}

GameBoard::~GameBoard()
{
}
