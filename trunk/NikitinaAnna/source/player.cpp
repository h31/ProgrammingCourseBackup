#include <iostream>
using namespace std;
#include"player.h"
#include"field.h"

Player::Player()
{
	View winner=blank;//������������� ���������-�����
	isWhiteTurn=true;//������ ��� ��������� �����, �������� ������
}
Player::~Player()
{
}