#include <iostream>
using namespace std;
#include"shashki.h"
//#include"player.h"
#include"field.h"
#include<locale.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	Field field;
	field.print();
	int Px;
	int Py;
	int x;
	int y;
	cout<<"������� ���������� ������, �� ������� ������ �����������."<<endl;
	cin>>Px>>Py;
	if(Px<1 || Px>8 || Py<1 || Py>8)
	{
		cout<<"������.�������� ������ ����������."<<endl;
		return -1;
	}
	Px--;
	Py--;
	cout<<"������� ���������� ������, ������� ������ �����������."<<endl;
	cin>>x>>y;
	if(x<1 || x>8 || y<1 || y>8)
	{
		cout<<"������.�������� ������ ����������."<<endl;
		return -1;
	}
	x--;
	y--;
	if(field.gameField[Px][Py]!=empty)//�������� �� ������� ������.
			{
				cout<<"������, �� ������� ������ �����������,  ������"<<endl;
				return -2;
		}
if(field.gameField[x][y]==empty)//�������� �� ������� ������.
			{
				cout<<"������ , ������� ������ �����������, �����"<<endl;
				return -3;
		}
	Checker checker;
	King king;
	if(field.gameField[x][y]==whiteShashka || field.gameField[x][y]==blackShashka)
		{
		checker.x=x;
		checker.y=y;
		if (checker.makeMove(Px,Py)==true)
		{
		field.permutation(Px,Py,checker.x, checker.y);
	field.transformKing();
			field.print();
		}
		else
			cout<<"����� ��� ���������� ��� ������ �����."<<endl;
		}
			if(field.gameField[x][y]==whiteKing || field.gameField[x][y]==blackKing )
			{
					king.x=x;
					king.y=y;
		if (king.makeMove(Px,Py)==true)
		{
			field.permutation(Px,Py,checker.x, checker.y);
			field.transformKing();
			field.print();
		}
		else
			cout<<"����� ��� ���������� ��� ������ �����."<<endl;
			}
	return 1;
}