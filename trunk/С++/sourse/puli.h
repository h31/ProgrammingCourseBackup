#ifndef PULI_H
#define PULI_H
#include <QPainter>
#include <QVector>

struct BulletCoordinates//���������� ����
{
    int x;
    int y;
};
struct AlphaMove//���� �������� ����
{
    int x;
    int y;
};

class Bullet:public QObject //����� ����
{
    Q_OBJECT
public:
    BulletCoordinates coords;
    AlphaMove alpha;
    int speed;//�������� ����
    int l;//����� ����

    Bullet();//�����������
    Bullet(const Bullet&);//���������� ���������� ��������� ���� �������
    Bullet& operator =(const Bullet&);//���������� ���������� ��������� ���� �������
    void drawp(QPainter &painter);//��������� ����
};
#endif // PULI_H
