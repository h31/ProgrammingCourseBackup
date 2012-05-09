#include "player.h"

player::player()
{
	hand.clear();
}

void player::enterName()
{
	cin>>name;
}
int player::makeBets()
{
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
	for (unsigned i=0; i<hand.size(); i++)
		cout<<hand[i].get_score()<<" "<<hand[i].get_suit()<<endl;
}
int player::countScore()
{
	score=0;
	for (int i=0; i<hand.size(); i++)
	{
		if (hand[i].get_score()=="2")
			score+=2;
		if (hand[i].get_score()=="3")
			score+=3;
		if (hand[i].get_score()=="4")
			score+=4;
		if (hand[i].get_score()=="5")
			score+=5;
		if (hand[i].get_score()=="6")
			score+=6;
		if (hand[i].get_score()=="7")
			score+=7;
		if (hand[i].get_score()=="8")
			score+=8;
		if (hand[i].get_score()=="9")
			score+=9;
		if (hand[i].get_score()=="10")
			score+=10;
		if (hand[i].get_score()=="J")
			score+=10;
		if (hand[i].get_score()=="Q")
			score+=10;
		if (hand[i].get_score()=="K")
			score+=10;
		if (hand[i].get_score()=="A")
			score+=11;
	
	}

	return score;
}
