#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include "mainwidget.h"
#include "gamelevel.h"
#include "game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMenu *Game;

    int **mat;
    QAction *newGameAction;
    QAction *SaveAction;
    QAction *CheckingAction;
    QAction *exitAction;
    QProgressBar *pb;
    MainWidget *field;
    QMenuBar *bar;
    Games *game;
public:
    MainWindow();
    GameLevel *level;

private:
    void CreateActions();
    void CreateMenu();

private slots:
    void SaveDialog();
    void Checking();
    void ChooseGameLevel();
};

#endif // MAINWINDOW_H
