#ifndef GAME_H
#define GAME_H

#include <QtGui>
#include "Field.h"
#include "Snake.h"
#include "Fructs.h"
#include "settings.h"

class Game : public QMainWindow
{
Q_OBJECT
public:
    Field * Gfield;
    Zmeika *Gzmeika;
    Fructs *Gfructs;

public:

    virtual void keyPressEvent(QKeyEvent * ev);
    void paintEvent(QPaintEvent*);
    void update();
    void initgame();
    void addfructs(int amount);
    void updatefield();
    bool checkPositionForFruct(int X,int Y);
private:
    bool Pause;

public:
    Game();

    ~Game() {}
};

#endif // GAME_H
