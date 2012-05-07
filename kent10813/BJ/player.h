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
        QString name;
		player ();
		
        void enterName(QString playerName);
		virtual int makeBets ();
		void takeCards ();
        virtual void show(QPainter &painter);
		int countScore ();

	};

#endif
