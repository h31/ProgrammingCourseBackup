#include "mainwindow.h"


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
 newGameAction = new QAction(tr("New Game"),this);
 connect(newGameAction,SIGNAL(triggered()),this,SLOT(createGame()));
 exitAction = new QAction(tr("Exit"),this);
 connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
 }

void MainWindow::createGame()
 {
 CreateMineField *dialog=new CreateMineField;
 connect(dialog,SIGNAL(acepted(int,int,int)),this,SLOT(createMField(int,int,int)));
 dialog->exec();
 }

void MainWindow::createMField(int a,int b,int c)
 {
 if(field)delete field;
 field=new MainWidget(a,b,c);
 this->resize(field->size());
 this->setCentralWidget(field);
 connect(field,SIGNAL(boom()),this,SLOT(GameOver()));
 connect(field,SIGNAL(progress(int)),pb,SLOT(setValue(int)));
 connect(field,SIGNAL(finish()),this,SLOT(Win()));

}

void MainWindow::GameOver()
 {

    QString a(tr("Game Over"));
 ExitDialog *e=new ExitDialog(a);
 connect(e,SIGNAL(accepted()),this,SLOT(createGame()));
 connect(e,SIGNAL(exits()),this,SLOT(close()));
 e->exec();

}

void MainWindow::CreateMenus()
 {
 bar=new QMenuBar(this);
 Game=bar->addMenu(tr("Game"));
 Game->addAction(newGameAction);
 Game->addSeparator();
 Game->addAction(exitAction);
 this->setMenuBar(bar);
 }


void MainWindow::Win()
 {

 QString a(tr("Your Win"));
 ExitDialog *e=new ExitDialog(a);
 connect(e,SIGNAL(accepted()),this,SLOT(createGame()));
 connect(e,SIGNAL(exits()),this,SLOT(close()));
 e->exec();

}
