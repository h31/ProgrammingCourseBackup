#include <iostream>
using namespace std;
#include"game.h"
#include"field.h"

Game::Game()
{
	View winner=blank;//Первоначально состояние-ничья
	isWhiteTurn=true;//Первый ход совершает игрок, играющий белыми
}
Game::~Game()
{
}
void Game::findWinner(Field& field)//проверка завершения игры и определение победителя
{
	if(field.endOfGame()==1)//проверка завершения игры. Если на поле нет черных шашек
		winner=white;
	if(field.endOfGame()==2)//если на поле нет черных шашек
		winner=black;
	if(field.endOfGame()==0)//если есть и черные, и белые шашки
		winner=blank;
}
/*void Game::sequenceMove(Player& player, Field& field,int Px, int Py, int x, int y)//задание последовательности ходов
{
	if(player.permutation(Px,Py,x,y,field)==true || (player.testEatenChecker(Px,Py,x, y,field)==true && player.secondCourse(Px,Py,field)==false))
		isWhiteTurn=!isWhiteTurn;//передача хода другому игроку
}*/