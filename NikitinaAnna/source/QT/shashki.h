#ifndef _shaski_h_
#define _shaski_h_
class Figure
{
public:
    Figure();
    ~Figure();
    virtual bool makeMove1(int Px, int Py)=0;//Ход белой фигуры
    virtual bool makeMove2(int Px, int Py)=0;//Ход черной фигуры
};
class Checker: public Figure//Класс обычная шашка
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
class King: public Figure//Класс дамка
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
