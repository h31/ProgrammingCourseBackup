#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <QtGui>
#include "deck.h"
#include "QInputDialog"
#include "firstdialog.h"
class player
	{
	protected:
		deque <card> hand;
		deck mydeck;

	public:
		int score;
		int bet;
        QString plname;
		player ();
		
        void enterName(QString name);
        virtual int makeBets (int bets);
		void takeCards ();
        virtual void show(QPainter &painter);
		int countScore ();

	};

#endif
