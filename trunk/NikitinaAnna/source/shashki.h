#ifndef _shaski_h_
#define _shaski_h_
class Figure
{
public:
	int x;
	int y;
	Figure();
	~Figure();
	virtual bool makeMove(int Px, int Py)=0;//Ход фигуры

};
class Checker: public Figure//Класс обычная шашка
{
public:
	Checker();
	~Checker();
	bool makeMove(int Px,int Py);


};
class King: public Figure//Класс дамка
{
public:
	King();
	~King();
	bool makeMove(int Px,int Py);
};
#endif