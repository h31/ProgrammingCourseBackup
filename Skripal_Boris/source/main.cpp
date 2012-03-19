#include "player.h"

#include <iostream>

using namespace std;
void main()
{
	Player game;
	int startX,startY,finishX,finishY;
	cout<<"White player turn now!"<<endl<<endl;
	game.board.printBoard();
	while(!game.haveWinner())
	{
		cin>>startX>>startY>>finishX>>finishY;
		startX--; startY--; finishX--; finishY--;
		game.makeTurn(startX,startY,finishX,finishY);
		cout<<endl;
		if(game.whitePlayerTurnNow()==true)
			cout<<"White player turn now!"<<endl<<endl;
		else
			cout<<"Black player turn now!"<<endl<<endl;
		game.board.printBoard();
	}
	return;
}