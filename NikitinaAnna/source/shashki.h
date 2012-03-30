#ifndef _shaski_h_
#define _shaski_h_
class Figure
{
public:
	int x;
	int y;
	Figure();
	~Figure();
	virtual bool makeMove(int Px, int Py)=0;//��� ������

};
class Checker: public Figure//����� ������� �����
{
public:
	Checker();
	~Checker();
	bool makeMove(int Px,int Py);


};
class King: public Figure//����� �����
{
public:
	King();
	~King();
	bool makeMove(int Px,int Py);
};
#endif