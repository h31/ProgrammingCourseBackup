#ifndef PULI_H
#define PULI_H
#include <QPainter>
struct BulletCoordinates
{
    int x;
    int y;
};
struct AlphaMove
{
    int x;
    int y;
};

class Bullet
{
    Q_OBJECT
public:
    BulletCoordinates coords;
    AlphaMove alpha;
    int r;
    int speed;
    void draw(QPainter &painter);
public slots:
    void moveBulletOnTimeout();

};
#endif // PULI_H
