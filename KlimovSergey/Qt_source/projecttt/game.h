#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QtGui>
#include"field.h"
#include"player.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

    QString fileName, complFile;
    Field field;
    Player player;

protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent * event);
    void mousePressEvent(QMouseEvent *event);
    
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
private slots:
    void on_actionStart_activated();

    void on_actionCheck_activated();

    void on_actionExit_activated();

private:
    Ui::Game *ui;

    void leftButtonPressEvent(QMouseEvent * event);
    void rightButtonPressEvent(QMouseEvent * event);
};

#endif // GAME_H
