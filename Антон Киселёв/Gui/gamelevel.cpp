#include "gamelevel.h"
#include "mainwidget.h"
#include "mainwindow.h"
#include "gameboard.h"
#include "game.h"
GameLevel::GameLevel():QDialog()
{
    easy = new QPushButton("&Easy");
    normal = new QPushButton("&Normal");
    hard = new QPushButton("&Hard");
    connect(easy, SIGNAL(clicked()),SLOT(firstlevel()));
    connect(normal, SIGNAL(clicked()),SLOT(secondlevel()));
    connect(hard, SIGNAL(clicked()),SLOT(thirdlevel()));
    lay = new QGridLayout;
    lay->addWidget(easy, 0, 0);
    lay->addWidget(normal, 1, 0);
    lay->addWidget(hard, 2, 0);
    this->setLayout(lay);
}

GameLevel::~GameLevel()
{
    delete[] easy;
    delete[] normal;
    delete[] hard;
    delete[] lay;
}

void GameLevel::firstlevel()
{
    int choice = 1;
    game = new Games;
    int num = game->GameLevel(choice);
    wgt = new MainWidget(num);
    wgt->show();
    this->close();
}

void GameLevel::secondlevel()
{
    int choice = 2;
    game = new Games;
    int num = game->GameLevel(choice);
    wgt = new MainWidget(num);
    wgt->show();
    this->close();
}

void GameLevel::thirdlevel()
{
    int choice = 2;
    game = new Games;
    int num = game->GameLevel(choice);
    wgt = new MainWidget(num);
    wgt->show();
    this->close();
}
