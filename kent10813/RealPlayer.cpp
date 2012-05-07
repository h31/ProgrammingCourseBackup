#include "RealPlayer.h"


int RealPlayer::makeBets()
{
	bet=0;
	cin>>bet;
/*	while (bet<=0)
	{
		//cout<<"Вы ввели запрещенную ставку, сделайте новую ставку ";
		cin>>bet;
	}
cout<<endl;*/
return bet;
}
