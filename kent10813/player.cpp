#include "player.h"

player::player()
{
	hand.clear();
}
void player::EnterName ()
{
	cout<<"������� ���"<<endl;
	cin>>name;
}
int player::MakeBets()
{
	cout<<"������� ������ ";
	cin>>bet;
	return bet;
}
void player::takeCards()
{
	mydeck.create_deck();
	hand.push_back(mydeck.pull_card());
}
void player::show()
{
	cout<<"���� �����"<<endl;
	for (unsigned i=0; i<hand.size(); i++)
		cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;
}
void player::MoreOrStop()
{
	cout<<"���� ����� ���, ������� 1, ���� ������ -����� �������"<<endl;
}