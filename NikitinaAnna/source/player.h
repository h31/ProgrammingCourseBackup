#ifndef _player_h_
#define _player_h_

enum View
{ 
	black,//�����, �������� �������
	white,//�����, �������� ������
	blank//�����
};

class Player
{
public:
	Player();
	~ Player();
	View winner;//��� �������
	bool isWhiteTurn;//��� �� ������ ������ �����
};
#endif