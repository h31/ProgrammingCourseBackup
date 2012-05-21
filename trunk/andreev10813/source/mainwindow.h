#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
 #include <QMenu>
 #include <QAction>
 #include <QProgressBar>
 #include <QMenuBar>
 #include <QStatusBar>

#include "MainWidget.h"
#include "CreateMineField.h"
#include "ExitDialog.h"

class MainWindow : public QMainWindow
 {
 Q_OBJECT
 QMenu *Game;

 QAction *newGameAction;
 QAction *exitAction;
 QProgressBar *pb;
 MainWidget *field;
 QMenuBar *bar;
 public:
 MainWindow();

private: /*FUNCTIONS*/
 void CreateActions();
 void CreateMenus();
 private slots:
 void createMField(int,int,int);
 void createGame();
 void GameOver();
 void Win();
 };

#endif // MAINWINDOW_H
