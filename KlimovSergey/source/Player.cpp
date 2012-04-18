#include"Player.h"

Player::Player()
{}

Player::~Player()
{}

int Player::ChangeStat(int st,Square square)
{
	square.status = st;
	return square.status;
}

bool Player::ChangeStat(int st,Field field,int x, int y)
{
	field.map[x][y].status = st;
	return true;
}