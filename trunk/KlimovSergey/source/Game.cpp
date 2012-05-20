#include"Game.h"

Game::Game()
{}

Game::~Game()
{}

bool Game::Start(Field &field, char* arg, Player &player)
{
	if(!field.loadField(arg))
		return false;
	field.createEmpty();
	cout<<field.height<<" "<<field.width<<endl;
	return true;
}

bool Game::Check(Field &field, char* arg)
{
	Field test;
	test.loadComplete(arg);
	for(int i=0; i<field.width; i++)
		{
			for(int j=0; j<field.height; j++)
			{
				if(test.getSqStat(i,j) == field.getSqStat(i,j))
					continue; 
				else
					cout<<endl;
					test.show();
					cout<<"Fail!"<<endl;
					return false;
			}
		}
	cout<<endl;
	test.show();
	cout<<"Success!"<<endl;
	return true;
}