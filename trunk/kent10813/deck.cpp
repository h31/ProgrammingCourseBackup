#include "deck.h"

void deck::create_deck ()
{
	for (int i=0;i<=ace;i++)
		for (int j=diamonds;j<=clubs;j++)
		{
			crd.set_suit((Suits)j);
			crd.set_value ((Values)i);
			Deck.push_back(crd);
		}
		shuffle();
	}
void deck::shuffle ()
{
	random_shuffle (Deck.begin(), Deck.end());
}
card deck::pull_card ()
{
	card crd=Deck.front();
	Deck.pop_front();
	return crd;
}