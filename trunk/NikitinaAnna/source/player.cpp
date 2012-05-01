#include <iostream>
using namespace std;
#include"player.h"
#include"field.h"

Player::Player()
{
	View winner=blank;//Первоначально состояние-ничья
	isWhiteTurn=true;//Первый ход совершает игрок, играющий белыми
}
Player::~Player()
{
}