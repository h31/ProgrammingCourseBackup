#include "Dealer.h"


void Dealer::EnterName()
{
	name="Dealer";
	cout<<name<<endl;
}
int Dealer::MakeBets()
{
	cout<<"����� ����������. ��� ������: "<<bet<<endl;
	return bet;
}
void Dealer::show()
{
	cout<<"����� ������: "<<endl;
	for (unsigned i=0; i<hand.size(); i++)
		cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;
}