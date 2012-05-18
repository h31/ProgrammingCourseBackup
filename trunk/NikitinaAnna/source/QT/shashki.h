#ifndef _shaski_h_
#define _shaski_h_
class Figure
{
public:
    Figure();
    ~Figure();
    virtual bool makeMove1(int Px, int Py)=0;//��� ����� ������
    virtual bool makeMove2(int Px, int Py)=0;//��� ������ ������
};
class Checker: public Figure//����� ������� �����
{
    int x;
    int y;
public:
    Checker();
    ~Checker();
    void setx(int Ox);
    void sety(int Oy);
    bool makeMove1(int Px,int Py);
    bool makeMove2(int Px,int Py);

};
class King: public Figure//����� �����
{
    int x;
    int y;
public:
    King();
    ~King();
    void setx(int Ox);
    void sety(int Oy);
    bool makeMove1(int Px,int Py);
    bool makeMove2(int Px,int Py);

};
#endif
