#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"
#include "savegamedialog.h"
#include "gamelevel.h"
#include "gameboard.h"
#include "game.h"
#include <QWidget>

MainWindow::MainWindow()
{
    CreateActions();
    CreateMenus();
    pb=new QProgressBar;
    pb->setMaximum(100);
    field=NULL;
    QStatusBar *b=statusBar();
    b=new QStatusBar;
    b->addWidget(pb);
    this->setStatusBar(b);
    connect(pb,SIGNAL(valueChanged(int)),b,SLOT(update()));
}

void MainWindow::CreateActions()
{
    newGameAction = new QAction("New Game",this);
    connect(newGameAction,SIGNAL(triggered()),this,SLOT(ChooseGameLevel()));
    SaveAction = new QAction("Save Game",this);
    connect(SaveAction,SIGNAL(triggered()),this,SLOT(SaveDialog()));
    CheckingAction = new QAction("Check",this);
    connect(CheckingAction,SIGNAL(triggered()),this,SLOT(Checking()));
    exitAction = new QAction("Exit",this);
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
}


void MainWindow::CreateMenu()
{
    bar = new QMenuBar(this);
    //Game = bar->addMenu(tr(«Game»))
    Game = bar->addMenu("Game");
    Game->addAction(newGameAction);
    Game->addSeparator();
    Game->addAction(CheckingAction);
    Game->addAction(SaveAction);
    Game->addSeparator();
    Game->addAction(exitAction);
    this->setMenuBar(bar);
}


void MainWindow::SaveDialog()
{
    SaveGameDialog *s = new SaveGameDialog;
    connect(s,SIGNAL(accepted()),this,SLOT(save_pressed()));
    connect(s,SIGNAL(exits()),this,SLOT(close()));
    s->exec();
}



void MainWindow::Checking()
{
    level->wgt->checking_Buttons();
}


void MainWindow::ChooseGameLevel()
{
    level = new GameLevel;
    level->exec();
}











































