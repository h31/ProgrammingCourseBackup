#include"shashki.h"

Figure::Figure()
{
}
Figure::~Figure()
{
}
Checker::Checker()
{
}
Checker::~Checker()
{
}
King::King()
{
}
King::~King()
{
}
bool Figure::makeMove1(int Px,int Py)
{
	return true;
}
bool Figure::makeMove2(int Px,int Py)
{
	return true;
}
bool Checker::makeMove1(int Px,int Py)//��� ����� �����
{
	if(Px-x==1 &&(y-Py==1 || Py-y==1))//������� ���(�� ���� �� �������� ������)
		return true;
	if((Px-x==2 || x-Px==2) &&(y-Py==2 || Py-y==2))//���, ��� ������� ����� "�������" ����� ����������
		return true;
	return false;
}
bool Checker::makeMove2(int Px,int Py)//��� ������ �����
{
	if(x-Px==1 &&(y-Py==1 || Py-y==1))
		return true;
	if((Px-x==2 || x-Px==2) &&(y-Py==2 || Py-y==2))
		return true;
	return false;
}
bool King::makeMove1(int Px,int Py)//��� ����� �����
{
	if((Px-x==Py-y || x-Px==Py-y) && (Px-x!=0 && Py-y!=0))
		return true;
	return false;
}
bool King::makeMove2(int Px,int Py)//��� ������ �����
{
	if((Px-x==Py-y || x-Px==Py-y) && (Px-x!=0 && Py-y!=0))
		return true;
	return false;
}