#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include<locale.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	Field field;
	Player player;
	Checker checker;
	King king;
	/*cout<<"������� ����������� ����."<<endl;
	cin>>field.size;
		if(field.size%2!=0)
		{
			cout<<"������� ������ �����������."<<endl;
			return -5;
		}*/
	field.fieldMake();//������� ����
	field.print();//������� ���� �� �����
	int Px;int Py;//���������� ������, �� ������� ����������
	int x;int y;//���������� ������,� ������� ����������
	int variable=0;//����������, ����� ������������ ����� ��� ��������
	while(player.winner=blank)//���� ���������� ���
	{
	if( variable==1)//�� ���� ���� � ���������� ��� ����� ����� ����� ����������, � ������  �������� ������ ��� ���� �� �����
	{
		x=Px;y=Py;//���������� �����, ������� ����� ����������� ��� ����������
		cout<<"����� ����� ������� ��� ��� � '������' ��� ���� ����� ���������� ����� ������ � ������������ "<<++x<<" "<<++y<<endl;
		x--;y--;
	}
	else//� ���� ������ ������ ������ ������ ���������� �����, ������� �� ����� �����������
	{
	cout<<"������� ���������� ������, ������� ������ �����������."<<endl;
	cin>>x>>y;
	x--;
	y--;
	while((x<0 || x>7 || y<0 || y>7) || 
		field.gameField[x][y]==empty || 
		((player.isWhiteTurn==true && (field.gameField[x][y]==blackShashka || field.gameField[x][y]==blackKing)) 
		|| (player.isWhiteTurn==false && (field.gameField[x][y]==whiteShashka  || field.gameField[x][y]==whiteKing))))//�������� ������� ������������ ���������
	{
	if(x<0 || x>7 || y<0 || y>7)
		cout<<"������.�������� ������ ����������."<<endl;
	if(x>=0 && x<=7 && y>=0 && y<=7 &&  field.gameField[x][y]==empty)//�������� �� ������� ������.
		cout<<"������ , ������� ������ �����������, �����"<<endl;
	if(x>=0 && x<=7 && y>=0 && y<=7 &&  field.gameField[x][y]!=empty && player.isWhiteTurn==false && (field.gameField[x][y]==whiteShashka  || field.gameField[x][y]==whiteKing))//�������� �� ������������ ����������� ����
		cout<<"������ ������ �����, �������� �������."<<endl;
	if(x>=0 && x<=7 && y>=0 && y<=7 &&  field.gameField[x][y]!=empty && player.isWhiteTurn==true  && (field.gameField[x][y]==blackShashka || field.gameField[x][y]==blackKing))//�������� �� ������������ ����������� ����
		cout<<"������ ������ �����, �������� ������."<<endl;
	cout<<"������� ���������� ������, ������� ������ �����������."<<endl;
	cin>>x>>y;
	x--;
	y--;
	}
	}
	cout<<"������� ���������� ������, �� ������� ������ �����������."<<endl;
	cin>>Px>>Py;
	Px--;
	Py--;
	while(Px<0 || Px>7 || Py<0 || Py>7 ||  field.gameField[Px][Py]!=empty 
		||(variable==1 && field.testEatenChecker(Px,Py, x, y)==false))//�������� ������� ������������ ���������, �� ������� ����������
	{
	if(Px<0 || Px>7 || Py<0 || Py>7)
		cout<<"������.�������� ������ ����������."<<endl;
	else
	{
	if(field.gameField[Px][Py]!=empty)//�������� �� ������� ������
		cout<<"������, �� ������� ������ �����������, ������"<<endl;
	else
	{
	if(variable==1 && field.testEatenChecker(Px,Py, x, y)==false)//���� ����� ��������� ������ ��� ������, �� ������ ����� ��� ������ "������" ���� ����������
		cout<<"������ ����� ���� '������' ����� ���������."<<endl;
	}
	}
	cout<<"������� ���������� ������, �� ������� ������ �����������."<<endl;
	cin>>Px>>Py;
	Px--;
	Py--;
	}
	variable=0;//�������� ����������
	if((player.isWhiteTurn==true && field.gameField[x][y]==whiteShashka ) || (player.isWhiteTurn==false && field.gameField[x][y]==blackShashka))//���� ������ ������ ������ �����, �������� ������(�������), � ����� ������� ��� �� �����(������)
	{
		checker.x=x;
		checker.y=y;
		if ((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==true))//���� �� ������ �����(������) ����� � �������� ��� �� �� �������� ������
		{
			if(field.permutation(Px,Py,checker.x, checker.y)==true)//�������� ������� �� ������ ��� �����(�� ���� ����� �� "�������" ����� ����������)
		{
			field.transformKing();//��������:�� ������ �� ����� ������
			field.print();//����� ����
			player.isWhiteTurn=!player.isWhiteTurn;//�������� ���� ������� ������
			}
			if(field.testEatenChecker(Px,Py,checker.x, checker.y)==true)//���� ����� ����� "������" ����� ����������
			{
			field.eatenChecker(Px,Py,checker.x, checker.y);//���������� ������ �������������� � �����
			field.transformKing();//��������:�� ������ �� ����� ������
			field.print();//����� ����
			if(field.secondCourse(Px,Py)==false)//���� ���������� ������ ���
				player.isWhiteTurn=!player.isWhiteTurn;//�������� ���� ������� ������
			else
			variable=1;//� �������� ������ ����������� ���������� �������� 1
			}
			/*if(field.permutation(Px,Py,checker.x, checker.y)==false && field.testEatenChecker(Px,Py,checker.x, checker.y)==false)//���� ���������� ������ �� �����������
				cout<<"����� ��� ���������� ��� ������ �����."<<endl;*/
		}
		if((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==false))
			cout<<"����� ��� ���������� ��� ������ �����."<<endl;
		}
	if((player.isWhiteTurn==true && field.gameField[x][y]==whiteKing ) || (player.isWhiteTurn==false && field.gameField[x][y]==blackKing))//���� ������ ������ ������ �����, �������� ������(�������), � ����� ������� ��� �� �����(������)
		{
		king.x=x;
		king.y=y;
		if ((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==true))//���� �� ������ �����(������) ����� � �������� ��� �� �� �������� ������
		{
			if(field.permutation(Px,Py,king.x, king.y)==true)//�������� ������� �� ������ ��� �����(�� ���� ����� �� "�������" ����� ����������)
			{
			field.print();//����� ����
			player.isWhiteTurn=!player.isWhiteTurn;//�������� ���� ������� ������
			}
			if(field.testEatenChecker(Px,Py,king.x, king.y)==true)//���� ����� ����� "������" ����� ����������
			{
				field.eatenChecker(Px,Py,king.x, king.y);//���������� ������ �������������� � �����
				field.print();//����� ����
				if(field.secondCourse(Px,Py)==false)//���� ���������� ������ ���
					player.isWhiteTurn=!player.isWhiteTurn;//�������� ���� ������� ������
				else
				variable=1;//� �������� ������ ����������� ���������� �������� 1
			}
			/*if(field.permutation(Px,Py,king.x, king.y)==false && field.testEatenChecker(Px,Py,king.x, king.y)==false)//���� ���������� ������ �� �����������
					cout<<"����� ��� ���������� ��� ������ �����."<<endl;*/
		}
		if((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==false))
			cout<<"����� ��� ���������� ��� ������ �����."<<endl;
		}
	if(field.endOfGame()==1)//�������� ���������� ����. ���� �� ���� ��� ������ �����
	{
		cout<<"������� �����,�������� ������."<<endl;
		player.winner=white;
	}
	if(field.endOfGame()==2)//���� �� ���� ��� ������ �����
	{
		cout<<"������� �����,�������� �������."<<endl;
		player.winner=black;
	}
	if(field.endOfGame()==0)//���� ���� � ������, � ����� �����
	player.winner=blank;
	}
	return 1;
}