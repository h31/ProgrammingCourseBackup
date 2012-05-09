#ifndef _DIALOG_H_
#define _DIALOG_H_

#include "RealPlayer.h"

class dialog
{
private:
	RealPlayer rp;
	
public:
	void setName();
	void setBet();
	void playerShow();
	void moreOrStop();
	void dealerShow();
	void dealerName();
	void wrongBet();
	void dealerMakeBet();
	void playerScore();
	void dealerScore();
	void prize();
	void isplayerWon();
	void isDealerWon();
	void isDraw();
	
};


#endif