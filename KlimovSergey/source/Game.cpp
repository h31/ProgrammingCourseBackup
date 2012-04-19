#include"Game.h"

Game::Game()
{}

Game::~Game()
{}

bool Game::Start(Field &field, char* arg, Player &player)
{
	field.loadField(arg);
	Square **tmp = new Square*[field.height];
	for(int i=0;i<field.height;i++)
		tmp[i] = new Square [field.width];
	for(int i=0; i<field.height; i++)
		{
			for(int j=0; j<field.width; j++)
			{
				tmp[i][j].status = 0;
				tmp[i][j].s.x = i;
				tmp[i][j].s.y = j;
				//cout << tmp[i][j].status<<" ";
			}
		//cout<<endl;
		}
	field.map = tmp;
	return true;
}