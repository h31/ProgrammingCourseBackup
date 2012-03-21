#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <locale.h>
#include <algorithm>
#include <deque>
#include <string>
#define Players 2
#define Cards_in_Hand 4
#define SuitsNumber 4
#define ValuesNumber 13
using namespace std;
string suits [4]= {"Diamonds","Hearts","Spades","Clubs"};
string values [13]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
enum suit {diamonds, hearts, spades, clubs};
enum values  {two,three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
	class card 
	{
	private:
		int su;
		int val;
	public:
		void set_suit (int s)
		{
			su=s;
		}
		void set_value (int v)
		{
			val=v;
		}
		string get_suit ()
		{
			return suits[su];
		}
		string get_score ()
		{
			return values [val];
		}
	};

	class deck 
	{
	private:
		deque<card> Deck;
	public:
		card crd;
		void create_deck ()
		{
			for (int i=0;i<ValuesNumber;i++)
				for (int j=0;j<SuitsNumber;j++)
				{
					crd.set_suit(j);
					crd.set_value (i);
					Deck.push_back(crd);
				
				}
			shuffle();
		}
		void shuffle ()
		{
			random_shuffle (Deck.begin(), Deck.end());
		}
		card pull_card ()
		{
			card crd=Deck.front();
			Deck.pop_front();
			return crd;
		}
	};

	class player
	{
	private:
		deque <card> hand;
	public:
		player ()
		{
			hand.clear();
		}
		void add (card c)
		{
			hand.push_back(c);
		}
		void show()
		{
			for (unsigned i=0; i<hand.size(); i++)
				cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;
		}
	};
	//в процессе разработки
	class Dealer : public player
	{
		void Turn()
		{

		}
	};
	class RealPlayer : public player
	{

	};
	//класс игра, пока для примера работоспособности (просто раздача заданного кол-ва карт заданному кол-ву игроков)
	class Game
	{
	public:
		player plr[Players];
		deck mydeck;
		void takeCards ()
		{
			mydeck.create_deck();
			for(int i = 0; i < Players; i++) 
			{
				
				for(int j = 0; j < Cards_in_Hand; j++)
			    plr[i].add(mydeck.pull_card());
				plr[i].show();
			}
		}
	};

#endif