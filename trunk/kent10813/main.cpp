#include "RealPlayer.h"
#include "Dealer.h"
#include "Game.h"
#include "Dialog.h"
#include <ctime>
int main()
{
	
	srand( time(NULL));
	setlocale (LC_ALL, "Russian");

	RealPlayer RPlayer;
	Dealer dealer;
	Game game;
	dialog chat;
	int Pscore, Dscore;
	chat.setName();
	chat.setBet();
	int bet= RPlayer.makeBets();

	while (bet<=0)
	{
		chat.wrongBet();
		bet=RPlayer.makeBets();
	}
	dealer.bet=bet;
	game.firstDispensation();

	
	game.gameContinue();
	game.dealerTakeCards();
	Pscore=game.playerScore();
	Dscore=game.dealerScore();
	chat.playerScore();
	cout<<Pscore<<endl;
	chat.dealerScore();
	cout<<Dscore<<endl;
	if (game.whoWon()==1)
		chat.isplayerWon();
	if (game.whoWon()==2)
		chat.isDealerWon();
	if (game.whoWon()==3)
		chat.isDraw();

	chat.prize();
	game.setCash(bet);
	return 0;
}


