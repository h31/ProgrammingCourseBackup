#include "RealPlayer.h"


int RealPlayer::MakeBets()
{
	bet=0;
	cout<<"������� ������"<<endl;
	cin>>bet;
	while (bet<=0)
	{
		cout<<"�� ����� ����������� ������, �������� ����� ������ ";
		cin>>bet;
	}
cout<<endl;
return bet;
}