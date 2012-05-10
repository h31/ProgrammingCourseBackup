#ifndef GAME_H
#define GAME_H
#include <Field.h>

class TurnText : public QGraphicsTextItem
{

public:
 TurnText(const QString q);

};


class Game
{
public:
    Game();
    void PreparingGame();
  //  void GameGame();
    QString str1;
    QString str2;

    TurnText* tu;
    QGraphicsScene* MainScene;

};




#endif // GAME_H
