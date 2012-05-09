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
	dlg.playerShow();
	plr.show();
}
void Game::gameContinue()
{
	
	dlg.moreOrStop();
	cin>>n;
	
	while (n=="1")
	{
	plr.takeCards();
	dlg.playerShow();
	plr.show();
	dlg.moreOrStop();
	cin>>n;
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
	dlg.dealerShow();
	dlr.show();
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
