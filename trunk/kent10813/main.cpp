#include "RealPlayer.h"
#include "Dealer.h"
#include <ctime>
int main()
{
	
	srand( time(NULL));
	setlocale (LC_ALL, "Russian");

	RealPlayer nikita;
	Dealer Ivan;
	int n;
	
	nikita.EnterName();
	int bet=nikita.MakeBets();
	nikita.takeCards();
	nikita.takeCards();
	Ivan.bet=bet;
	
	Ivan.takeCards();
	Ivan.takeCards();
	nikita.show();
	nikita.MoreOrStop();
	cin>>n;
	
	while (n==1)
	{
	nikita.takeCards();
	nikita.show();
	nikita.MoreOrStop();
	Ivan.takeCards();
	cin>>n;
	}
	
	
	Ivan.EnterName();
	Ivan.MakeBets();
	Ivan.show();
	
	return 0;
}


