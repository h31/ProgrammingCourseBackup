#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include"game.h"
#include<locale.h>

int main(void)
{
	Field field;
	Player player;
	Game game;
	Checker checker;
	King king;
	field.fieldMake();
	for(int i=0;i<size;i++)//������� ���� �� �����
	{
		for(int j=0;j<size;j++)
			cout<<field.gameField[i][j];
		cout<<endl;
	}
	cout<<endl;
	setlocale(LC_ALL, "Russian");
	checker.x=2; checker.y=3;//�������� ����� �����
	if(checker.makeMove1(4,5)==true)
		cout<<"����� ��������� ������� ����� ����������"<<endl;
	else
		cout<<"����� ����������� ������� ����� ����������"<<endl;
	if(checker.makeMove1(3,2)==true)
		cout<<"����� ��������� ��������� ������� ���"<<endl;
	else
		cout<<"����� ����������� ��������� ������� ���"<<endl;
	king.x=2; king.y=3;//�������� ����� �����
	if(king.makeMove1(6,7)==true)
		cout<<"����� ��������� ������� ����� ����������"<<endl;
	else
		cout<<"����� ����������� ������� ����� ����������"<<endl;
	if(checker.makeMove1(0,1)==true)
		cout<<"����� ��������� ��������� ������� ���"<<endl;
	else
		cout<<"����� ����������� ��������� ������� ���"<<endl;
	if(player.permutation(3,2,2, 1,field)==true)
		cout<<"������� ��� ����� ������ ����������� ���������, ���� �������������"<<endl;
	else
		cout<<"������� ��� ����� ������ ����������� �����������, ���� �� �������������"<<endl;
	if(player.permutation(4,1,5, 0,field)==true)
			cout<<"������� ��� ������ ������ ����������� ���������, ���� �������������"<<endl;
	else
		cout<<"������� ��� ������ ������ ����������� �����������, ���� �� �������������"<<endl;
	if(player.testEatenChecker(5,0, 3, 2,field)==true)
	{
			cout<<"����� ����� ��������� ������� ������ ����������, ���� �������������"<<endl;
			player.eatenChecker(5,0, 3, 2,field);
	}
	else
		cout<<"����� ����� ����������� ������� ������ ����������, ���� �� �������������"<<endl;
	if(player.secondCourse(5,0,field )==true)
		cout<<"������ ��� ����� ��������� ������"<<endl;
	else
		cout<<"������ ��� ����� ����������� ������"<<endl;
	if(player.testEatenChecker(7,2,5,0,field)==true)
		player.eatenChecker(7,2, 5, 0,field);
	field.transformKing();
	if(field.gameField[7][2]==whiteKing)
		cout<<"����������� ����� � ����� ��������� �������"<<endl;
	else
		cout<<"����������� ����� � ����� �� ��������� �������"<<endl;
	field.endOfGame();
	game.findWinner(field);
	if(game.winner=white)
		cout<<"������� �����,�������� ������.��� �����."<<endl;
	else
		cout<<"���������� ������ �������"<<endl;
	return 0;
}
	

