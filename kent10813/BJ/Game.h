#ifndef _GAME_H_
#define _GAME_H_
#include "RealPlayer.h"
#include "Dealer.h"
#include "Dialog.h"

class Game
{
private:
    //RealPlayer plr;
	Dealer dlr;
	dialog dlg;
	int pscore, dscore, cash;
    QString n;
    QPainter p;
public:
    RealPlayer plr;
	void takeCards();
	int playerScore();
	int dealerScore();
	void firstDispensation();
	void dealerTakeCards();
	void gameContinue();
	int whoWon();
    int setCash(int bet);
    RealPlayer getPlayer();
};



#endif
