#include <iostream>
using namespace std;
#include"game.h"
#include"field.h"

Game::Game()
{
	View winner=blank;//������������� ���������-�����
	isWhiteTurn=true;//������ ��� ��������� �����, �������� ������
}
Game::~Game()
{
}
void Game::findWinner(Field& field)//�������� ���������� ���� � ����������� ����������
{
	if(field.endOfGame()==1)//�������� ���������� ����. ���� �� ���� ��� ������ �����
		winner=white;
	if(field.endOfGame()==2)//���� �� ���� ��� ������ �����
		winner=black;
	if(field.endOfGame()==0)//���� ���� � ������, � ����� �����
		winner=blank;
}
/*void Game::sequenceMove(Player& player, Field& field,int Px, int Py, int x, int y)//������� ������������������ �����
{
	if(player.permutation(Px,Py,x,y,field)==true || (player.testEatenChecker(Px,Py,x, y,field)==true && player.secondCourse(Px,Py,field)==false))
		isWhiteTurn=!isWhiteTurn;//�������� ���� ������� ������
}*/