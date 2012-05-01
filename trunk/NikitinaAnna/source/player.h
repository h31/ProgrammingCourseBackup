#ifndef _player_h_
#define _player_h_

enum View
{ 
	black,//Игрок, играющий черными
	white,//Игрок, играющий белыми
	blank//Ничья
};

class Player
{
public:
	Player();
	~ Player();
	View winner;//Кто выиграл
	bool isWhiteTurn;//Кто на данный момент ходит
};
#endif