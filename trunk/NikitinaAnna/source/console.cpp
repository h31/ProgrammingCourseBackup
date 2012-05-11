#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include"game.h"
#include"console.h"
#include<locale.h>

void Console::print(Field& field)//����� ����
{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<field.gameField[i][j];
		cout<<endl;
	}
		cout<<endl;
}
void Console::dialog( int Px,int Py, int variable,Field& field, Player& player, Game& game)
{
	setlocale(LC_ALL, "Russian");
	if( variable==1)//�� ���� ���� � ���������� ��� ����� ����� ����� ����������, � ������  �������� ������ ��� ���� �� �����
	{
		conx=Px;cony=Py;//���������� �����, ������� ����� ����������� ��� ����������
		cout<<"����� ����� ������� ��� ��� � '������' ��� ���� ����� ���������� ����� ������ � ������������ "<<++conx<<" "<<++cony<<endl;
		conx--;cony--;
	}
	else//� ���� ������ ������ ������ ������ ���������� �����, ������� �� ����� �����������
	{
	cout<<"������� ���������� ������, ������� ������ �����������."<<endl;
	cin>>conx>>cony;
	conx--;cony--;
	while((conx<0 || conx>7 || cony<0 || cony>7) || 
		field.gameField[conx][cony]==empty || 
		((game.isWhiteTurn==true && (field.gameField[conx][cony]==blackShashka || field.gameField[conx][cony]==blackKing)) 
		|| (game.isWhiteTurn==false && (field.gameField[conx][cony]==whiteShashka  || field.gameField[conx][cony]==whiteKing))))//�������� ������� ������������ ���������
	{
	if(conx<0 || conx>7 || cony<0 || cony>7)
		cout<<"������.�������� ������ ����������."<<endl;
	if(conx>=0 && conx<=7 && cony>=0 && cony<=7 &&  field.gameField[conx][cony]==empty)//�������� �� ������� ������.
		cout<<"������ , ������� ������ �����������, �����"<<endl;
	if(conx>=0 && conx<=7 && cony>=0 && cony<=7 &&  field.gameField[conx][cony]!=empty && game.isWhiteTurn==false && (field.gameField[conx][cony]==whiteShashka  || field.gameField[conx][cony]==whiteKing))//�������� �� ������������ ����������� ����
		cout<<"������ ������ �����, �������� �������."<<endl;
	if(conx>=0 && conx<=7 && cony>=0 && cony<=7 &&  field.gameField[conx][cony]!=empty && game.isWhiteTurn==true  && (field.gameField[conx][cony]==blackShashka || field.gameField[conx][cony]==blackKing))//�������� �� ������������ ����������� ����
		cout<<"������ ������ �����, �������� ������."<<endl;
	cout<<"������� ���������� ������, ������� ������ �����������."<<endl;
	cin>>conx>>cony;
	conx--;cony--;
	}
	}
	cout<<"������� ���������� ������, �� ������� ������ �����������."<<endl;
	cin>>conPx>>conPy;
	conPx--;conPy--;
	while(conPx<0 || conPx>7 || conPy<0 || conPy>7 ||  field.gameField[conPx][conPy]!=empty 
		||(variable==1 && player.testEatenChecker(conPx,conPy, conx, cony,field)==false))//�������� ������� ������������ ���������, �� ������� ����������
	{
	if(conPx<0 || conPx>7 || conPy<0 || conPy>7)
		cout<<"������.�������� ������ ����������."<<endl;
	else
	{
	if(field.gameField[conPx][conPy]!=empty)//�������� �� ������� ������
		cout<<"������, �� ������� ������ �����������, ������"<<endl;
	else
	{
	if(variable==1 && player.testEatenChecker(conPx,conPy, conx, cony,field)==false)//���� ����� ��������� ������ ��� ������, �� ������ ����� ��� ������ "������" ���� ����������
		cout<<"������ ����� ���� '������' ����� ���������."<<endl;
	}
	}
	cout<<"������� ���������� ������, �� ������� ������ �����������."<<endl;
	cin>>conPx>>conPy;
	conPx--;conPy--;
	}
	variable=0;//�������� ����������
}
void Console::check(Field& field,Checker& checker,King& king,int Px, int Py, int x, int y)
{
	setlocale(LC_ALL, "Russian");
	if((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==false))
			cout<<"����� ��� ���������� ��� ������ �����."<<endl;
	if((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==false))
			cout<<"����� ��� ���������� ��� ������ �����."<<endl;
}
void Console::printResult(Game& game)
{
	setlocale(LC_ALL, "Russian");
	if(game.winner=white)
		cout<<"������� �����,�������� ������."<<endl;
	if(game.winner=black)
		cout<<"������� �����,�������� �������."<<endl;
}
int Console::getConx()
{
	return conx;
}
int Console::getCony()
{
	return cony;
}
int Console::getConPx()
{
	return conPx;
}
int Console::getConPy()
{
	return conPy;
}