#include "Game.h"

Game::Game()
{
    plr= new RealPlayer;
    dlr= new Dealer;
    dscore= new int;
    pscore=new int;
}
int Game::playerScore()
{
    *pscore=plr->countScore();
    return *pscore;
}
int Game::dealerScore()
{
    *dscore=dlr->countScore();
    return *dscore;
}
RealPlayer Game::getPlayer()
{
    return *plr;
}

void Game::firstDispensation()
{
 /*   plr.takeCards();
	plr.takeCards();
	dlr.takeCards();
	dlr.takeCards();
    plr.show(p);*/
}

void Game::dealerTakeCards()
{
    dealerScore();
    while (*dscore<17)
    {
        dlr->takeCards();
		dealerScore();
	}
   // dlr.show(p);
}
int Game::whoWon()
{
    if ((*pscore>*dscore&&*pscore<=21)||(*pscore<=21&&*dscore>21))
        return 1;
    if ((*dscore>*pscore&&*dscore<=21)||(*dscore<=21&&*pscore>21))
		return 2;
    if (*pscore==*dscore&&*pscore<=21&&*dscore<=21||(*pscore>21&&*dscore>21))
        return 3;

}
int Game::setCash(int  bet)
{
   /* cash=bet;
    return cash;*/
    return 0;
}
