#include"Player.h"

Player::Player()
{}

Player::~Player()
{}

int Player::ChangeStat(int st,Square &square)
{
	square.setStat(st);
	return square.getStat();
}

bool Player::ChangeStat(int st,Field &field,int x, int y)
{
	field.setSqStat(st,x,y);
	return true;
}