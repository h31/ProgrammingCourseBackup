#ifndef PULI_H
#define PULI_H
#include <QPainter>
#include <QVector>

struct BulletCoordinates//координаты пули
{
    int x;
    int y;
};
struct AlphaMove//угол движения пули
{
    int x;
    int y;
};

class Bullet:public QObject //класс пуля
{
    Q_OBJECT
public:
    BulletCoordinates coords;
    AlphaMove alpha;
    int speed;//скорость пули
    int l;//длина пули

    Bullet();//контсруктор
    Bullet(const Bullet&);//компилятор потребовал написания этой функции
    Bullet& operator =(const Bullet&);//компилятор потребовал написания этой функции
    void drawp(QPainter &painter);//рисование пули
};
#endif // PULI_H
