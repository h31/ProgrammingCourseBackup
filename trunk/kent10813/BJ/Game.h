#ifndef _GAME_H_
#define _GAME_H_
#include "RealPlayer.h"
#include "Dealer.h"
#include "Dialog.h"

class Game
{
private:
    //RealPlayer plr;

	dialog dlg;
    int *pscore, *dscore, cash;
    QString n;
    QPainter p;
public:
    Game();
    RealPlayer *plr;
    Dealer *dlr;
	void takeCards();
	int playerScore();
	int dealerScore();
	void firstDispensation();
	void dealerTakeCards();
	int whoWon();
    int setCash(int bet);
    RealPlayer getPlayer();
};



#endif
