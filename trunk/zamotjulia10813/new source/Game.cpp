#include "Game.h"
Game::Game (int Polesize, int Zmx, int Zmy, int Zmnapx, int Zmnapy, int numberFr) 
{
	Zmei = new Zmeika (Zmx, Zmy, Zmnapx, Zmnapy);
	Fruits = new Fructs (numberFr);
	Fruits-> add (Polesize,Polesize);
	p = new Pole (Polesize,Polesize, Fruits, Zmei ); 
};

void Game::Upd()
{
	system ("cls");
	//cout << '\r';
	p->show();
	_sleep(200);
	
}