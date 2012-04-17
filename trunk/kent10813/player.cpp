#include "player.h"

player::player()
{
	hand.clear();
}
void player::EnterName ()
{
	cout<<"Введите имя"<<endl;
	cin>>name;
}
int player::MakeBets()
{
	cout<<"Введите ставку ";
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
	cout<<"Ваши карты"<<endl;
	for (unsigned i=0; i<hand.size(); i++)
		cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;
}
void player::MoreOrStop()
{
	cout<<"Если взять еще, нажмите 1, если хватит -любую клавишу"<<endl;
}