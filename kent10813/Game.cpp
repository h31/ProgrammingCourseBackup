#include "Game.h"


int Game::playerScore()
{
	Pscore=plr.countScore();
	return Pscore;
}
int Game::dealerScore()
{
	Dscore=dlr.countScore();
	return Dscore;
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
	while (Dscore<17)
	{
		dlr.takeCards();
		dealerScore();
	}
	dlg.dealerShow();
	dlr.show();
}
int Game::whoWon()
{
	if ((Pscore>Dscore&&Pscore<=21)||(Pscore<=21&&Dscore>21)|| (Pscore>21&&Dscore>21))
		return 1;
	if ((Dscore>Pscore&&Dscore<=21)||(Dscore<=21&&Pscore>21))
		return 2;
	if (Pscore==Dscore&&Pscore<=21&&Dscore<=21)
		return 3;
}
void Game::setCash(int  bet)
{
	cash=bet;
	cout<<2*cash<<endl;
}
