#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QLabel>
#include "game.h"
#include "mainwidget.h"

class GameLevel : public QDialog
{
    Q_OBJECT

    QPushButton *easy, *normal, *hard;
    QGridLayout *lay;
    Games *game;
    
public:
    GameLevel();
    MainWidget* wgt;
    ~GameLevel();

public slots:
    void firstlevel();
    void secondlevel();
    void thirdlevel();

};

#endif // GAMELEVEL_H
