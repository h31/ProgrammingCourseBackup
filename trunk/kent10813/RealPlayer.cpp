#include "RealPlayer.h"


int RealPlayer::MakeBets()
{
	bet=0;
	cout<<"Введите ставку"<<endl;
	cin>>bet;
	while (bet<=0)
	{
		cout<<"Вы ввели запрещенную ставку, сделайте новую ставку ";
		cin>>bet;
	}
cout<<endl;
return bet;
}