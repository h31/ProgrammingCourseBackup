#include "Game.h"


int Game::playerScore()
{
	pscore=plr.countScore();
	return pscore;
}
int Game::dealerScore()
{
	dscore=dlr.countScore();
	return dscore;
}
void Game::firstDispensation()
{
	plr.takeCards();
	plr.takeCards();
	dlr.takeCards();
	dlr.takeCards();
    plr.show(p);
}
void Game::gameContinue()
{
    //cin>>n;
	
	while (n=="1")
	{
	plr.takeCards();
   // plr.show(p);
    //cin>>n;
	}
}
void Game::dealerTakeCards()
{
	dealerScore();
	while (dscore<17)
	{
		dlr.takeCards();
		dealerScore();
	}
   // dlr.show(p);
}
int Game::whoWon()
{
	if ((pscore>dscore&&pscore<=21)||(pscore<=21&&dscore>21))
		return 1;
	if ((dscore>pscore&&dscore<=21)||(dscore<=21&&pscore>21))
		return 2;
	if (pscore==dscore&&pscore<=21&&dscore<=21||(pscore>21&&dscore>21))
		return 3;
}
void Game::setCash(int  bet)
{
	cash=bet;
	cout<<2*cash<<endl;
}
