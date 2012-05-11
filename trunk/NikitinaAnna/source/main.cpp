#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include"game.h"
#include"console.h"
#include<locale.h>

int main(void)
{
	Field field;
	Player player;
	Game game;
	Checker checker;
	King king;
	Console console;
	int Px;int Py;//���������� ������, �� ������� ����������
	int x;int y;//���������� ������,� ������� ����������
	Px=-1;Py=-1;
	x=-1; y=-1; 
	int variable=0;//����������, ����� ������������ ����� ��� ��������
	field.fieldMake();//������� ����
	console.print(field);//������� ���� �� �����
	while(game.winner=blank)//���� ���������� ���
	{
	console.dialog( Px, Py,variable,field, player,game);
	x=console.conx; y=console.cony;
	Px=console.conPx; Py=console.conPy;
	//game.sequenceMove(field,Px,Py,x,y);
	if((game.isWhiteTurn==true && field.gameField[x][y]==whiteShashka ) || (game.isWhiteTurn==false && field.gameField[x][y]==blackShashka))//���� ������ ������ ������ �����, �������� ������(�������), � ����� ������� ��� �� �����(������)
	{
		checker.x=x;
		checker.y=y;
		if ((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==true))//���� �� ������ �����(������) ����� � �������� ��� �� �� �������� ������
		{
			if(player.permutation(Px,Py,checker.x, checker.y,field)==true)//�������� ������� �� ������ ��� �����(�� ���� ����� �� "�������" ����� ����������)
		{
			field.transformKing();//��������:�� ������ �� ����� ������
			console.print(field);//����� ����
			}
			if(player.testEatenChecker(Px,Py,checker.x, checker.y,field)==true)//���� ����� ����� "������" ����� ����������
			{
			player.eatenChecker(Px,Py,checker.x, checker.y,field);//���������� ������ �������������� � �����
			field.transformKing();//��������:�� ������ �� ����� ������
			console.print(field);//����� ����
			if(player.secondCourse(Px,Py,field)==true)//���� �������� ������ ���
				variable=1;//� �������� ������ ����������� ���������� �������� 1
			}
			/*if(field.permutation(Px,Py,checker.x, checker.y)==false && field.testEatenChecker(Px,Py,checker.x, checker.y)==false)//���� ���������� ������ �� �����������
				cout<<"����� ��� ���������� ��� ������ �����."<<endl;*/
		}
		console.check(field,checker,king,Px,Py, x,y);
		}
	if((game.isWhiteTurn==true && field.gameField[x][y]==whiteKing ) || (game.isWhiteTurn==false && field.gameField[x][y]==blackKing))//���� ������ ������ ������ �����, �������� ������(�������), � ����� ������� ��� �� �����(������)
		{
		king.x=x;
		king.y=y;
		if ((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==true))//���� �� ������ �����(������) ����� � �������� ��� �� �� �������� ������
		{
			if(player.permutation(Px,Py,king.x,king.y,field)==true)//�������� ������� �� ������ ��� �����(�� ���� ����� �� "�������" ����� ����������)
				console.print(field);//����� ����
			if(player.testEatenChecker(Px,Py,king.x, king.y,field)==true)//���� ����� ����� "������" ����� ����������
			{
				player.eatenChecker(Px,Py,king.x, king.y,field);//���������� ������ �������������� � �����
				console.print(field);//����� ����
				if(player.secondCourse(Px,Py,field)==true)//���� ���������� ������ ���
					variable=1;//� �������� ������ ����������� ���������� �������� 1
			}
			/*if(field.permutation(Px,Py,king.x, king.y)==false && field.testEatenChecker(Px,Py,king.x, king.y)==false)//���� ���������� ������ �� �����������
					cout<<"����� ��� ���������� ��� ������ �����."<<endl;*/
		}
		console.check(field,checker,king,Px,Py, x,y);
		}
	game.findWinner(field);
	}
	console.endOfGame(game);
	return 1;
}