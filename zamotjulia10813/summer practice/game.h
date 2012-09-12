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
    bool checkSnakeAlive();
    void SetPause(bool NPause);
    bool GetPause();
    float MathPoints();	//расчет очков
    int GetCycles();
    bool SetCycles(int newNCycles);
    void IncCycles();
    bool SaveToFile();
    bool LoadGame();
private:
    bool Pause;
    int Cycles;		//количество движений  змеи с начала игры

public:
    Game();

    ~Game() {}
};

#endif // GAME_H
