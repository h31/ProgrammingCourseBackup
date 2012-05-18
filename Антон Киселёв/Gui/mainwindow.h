#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLayout>
#include <QEvent>
#include "savedgames.h"
#include "game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMenu *Game;

    QAction *newGameAction;
    QAction *loadGame;
    QAction *saveAction;
    QAction *checkingAction;
    QAction *exitAction;

    QMenuBar *bar;
public:
    bool is_New_Game_Activated;
    bool is_Load_Game_Activated;
    bool is_Mouse_Clicked;
    bool is_Checking;
    Field* GameField;
    SavedGames *save_game;

    QPushButton *easy, *normal, *hard;
    QGridLayout *lay, *savelay;
    QPushButton *save, *cancel;
    SavedGames* SaveGame;

    QDialog* leveldialog;
    QDialog* savedialog;

    MainWindow();
    ~MainWindow();
    int defined_ixRow;
    int defined_ixCol;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * ev);
    void insert_in_cell(int ixRow, int ixCol);
    void CreateNewGame(int choice);
    void Save_Graphic_Options();

private:
    void CreateActions();
    void CreateMenu();

private slots:
    void SaveDialog();
    void LoadGame();
    void Checking();
    void ChoiceLevel();
    void firstlevel();
    void secondlevel();
    void thirdlevel();
    void save_pressed();
    void cancel_press();
};

#endif // MAINWINDOW_H
