#ifndef _shaski_h_
#define _shaski_h_
class Figure
{
public:
	int x;
	int y;
	Figure();
	~Figure();
	virtual bool makeMove1(int Px, int Py)=0;//��� ����� ������
	virtual bool makeMove2(int Px, int Py)=0;//��� ������ ������
};
class Checker: public Figure//����� ������� �����
{
public:
	Checker();
	~Checker();
	bool makeMove1(int Px,int Py);
	bool makeMove2(int Px,int Py);

};
class King: public Figure//����� �����
{
public:
	King();
	~King();
	bool makeMove1(int Px,int Py);
	bool makeMove2(int Px,int Py);

};
#endif