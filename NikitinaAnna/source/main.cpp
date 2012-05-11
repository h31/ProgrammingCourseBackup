#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include"game.h"
#include"console.h"
#include<locale.h>

int main(void)
{
	Field field;
	Player player;
	Game game;
	Checker checker;
	King king;
	Console console;
	int Px;int Py;//координаты €чейки, на которую перемещаем
	int x;int y;//координаты €чейки,с которой перемещаем
	Px=-1;Py=-1;
	x=-1; y=-1; 
	int variable=0;//переменна€, будет использована позже дл€ проверки
	field.fieldMake();//создаем поле
	console.print(field);//выводим поле на экран
	while(game.winner=blank)//пока победител€ нет
	{
	console.dialog( Px, Py,variable,field, player,game);
	x=console.conx; y=console.cony;
	Px=console.conPx; Py=console.conPy;
	//game.sequenceMove(field,Px,Py,x,y);
	if((game.isWhiteTurn==true && field.gameField[x][y]==whiteShashka ) || (game.isWhiteTurn==false && field.gameField[x][y]==blackShashka))//если сейчас должен ходить игрок, играющий белыми(черными), и шашка выбрана так же бела€(черна€)
	{
		checker.x=x;
		checker.y=y;
		if ((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==true))//если на €чейке бела€(черна€) шашка и возможен ход ее на заданную €чейку
		{
			if(player.permutation(Px,Py,checker.x, checker.y,field)==true)//проверка функции на просто ход шашки(то есть шашка не "съедает" шашку противника)
		{
			field.transformKing();//проверка:не станет ли шашка дамкой
			console.print(field);//вывод пол€
			}
			if(player.testEatenChecker(Px,Py,checker.x, checker.y,field)==true)//если шашка может "съесть" шашку противника
			{
			player.eatenChecker(Px,Py,checker.x, checker.y,field);//производим нужные преобразовани€ с полем
			field.transformKing();//проверка:не станет ли шашка дамкой
			console.print(field);//вывод пол€
			if(player.secondCourse(Px,Py,field)==true)//если возможен второй ход
				variable=1;//в обратном случае присваиваем переменной значение 1
			}
			/*if(field.permutation(Px,Py,checker.x, checker.y)==false && field.testEatenChecker(Px,Py,checker.x, checker.y)==false)//если предыдущие пункты не выполн€ютс€
				cout<<"“акой ход невозможен дл€ данной шашки."<<endl;*/
		}
		console.check(field,checker,king,Px,Py, x,y);
		}
	if((game.isWhiteTurn==true && field.gameField[x][y]==whiteKing ) || (game.isWhiteTurn==false && field.gameField[x][y]==blackKing))//если сейчас должен ходить игрок, играющий белыми(черными), и дамка выбрана так же бела€(черна€)
		{
		king.x=x;
		king.y=y;
		if ((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==true))//если на €чейке бела€(черна€) дамка и возможен ход ее на заданную €чейку
		{
			if(player.permutation(Px,Py,king.x,king.y,field)==true)//проверка функции на просто ход дамки(то есть дамка не "съедает" шашку противника)
				console.print(field);//вывод пол€
			if(player.testEatenChecker(Px,Py,king.x, king.y,field)==true)//если дамка может "съесть" шашку противника
			{
				player.eatenChecker(Px,Py,king.x, king.y,field);//производим нужные преобразовани€ с полем
				console.print(field);//вывод пол€
				if(player.secondCourse(Px,Py,field)==true)//если невозможен второй ход
					variable=1;//в обратном случае присваиваем переменной значение 1
			}
			/*if(field.permutation(Px,Py,king.x, king.y)==false && field.testEatenChecker(Px,Py,king.x, king.y)==false)//если предыдущие пункты не выполн€ютс€
					cout<<"“акой ход невозможен дл€ данной дамки."<<endl;*/
		}
		console.check(field,checker,king,Px,Py, x,y);
		}
	game.findWinner(field);
	}
	console.endOfGame(game);
	return 1;
}