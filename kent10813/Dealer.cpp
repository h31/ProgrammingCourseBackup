#include "Dealer.h"


void Dealer::EnterName()
{
	name="Dealer";
	cout<<name<<endl;
}
int Dealer::MakeBets()
{
	cout<<"Дилер сравнивает. Его ставка: "<<bet<<endl;
	return bet;
}
void Dealer::show()
{
	cout<<"Карты дилера: "<<endl;
	for (unsigned i=0; i<hand.size(); i++)
		cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;
}