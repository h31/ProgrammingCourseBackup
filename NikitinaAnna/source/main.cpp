#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include<locale.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	Field field;
	Player player;
	Checker checker;
	King king;
	/*cout<<"Введите размерность поля."<<endl;
	cin>>field.size;
		if(field.size%2!=0)
		{
			cout<<"Введите другую размерность."<<endl;
			return -5;
		}*/
	field.fieldMake();//создаем поле
	field.print();//выводим поле на экран
	int Px;int Py;//координаты ячейки, на которую перемещаем
	int x;int y;//координаты ячейки,с которой перемещаем
	int variable=0;//переменная, будет использована позже для проверки
	while(player.winner=blank)//пока победителя нет
	{
	if( variable==1)//то есть если в предыдущий ход шашка съела шашку противника, и сейчас  возможен второй ход этой же шашки
	{
		x=Px;y=Py;//координаты шашки, которую хотим переместить уже определены
		cout<<"Игрок может сходить еще раз и 'съесть' еще одну шашку противника своей шашкой с координатами "<<++x<<" "<<++y<<endl;
		x--;y--;
	}
	else//в ином случае просим игрока ввести координаты шашки, которую он хочет переместить
	{
	cout<<"Введите координаты ячейки, которую хотите переместить."<<endl;
	cin>>x>>y;
	x--;
	y--;
	while((x<0 || x>7 || y<0 || y>7) || 
		field.gameField[x][y]==empty || 
		((player.isWhiteTurn==true && (field.gameField[x][y]==blackShashka || field.gameField[x][y]==blackKing)) 
		|| (player.isWhiteTurn==false && (field.gameField[x][y]==whiteShashka  || field.gameField[x][y]==whiteKing))))//проверка условий правильности координат
	{
	if(x<0 || x>7 || y<0 || y>7)
		cout<<"Ошибка.Выберите другие координаты."<<endl;
	if(x>=0 && x<=7 && y>=0 && y<=7 &&  field.gameField[x][y]==empty)//Проверка на пустоту ячейки.
		cout<<"Ячейка , которую хотите переместить, пуста"<<endl;
	if(x>=0 && x<=7 && y>=0 && y<=7 &&  field.gameField[x][y]!=empty && player.isWhiteTurn==false && (field.gameField[x][y]==whiteShashka  || field.gameField[x][y]==whiteKing))//проверка на правильность очередности хода
		cout<<"Должен ходить игрок, играющий черными."<<endl;
	if(x>=0 && x<=7 && y>=0 && y<=7 &&  field.gameField[x][y]!=empty && player.isWhiteTurn==true  && (field.gameField[x][y]==blackShashka || field.gameField[x][y]==blackKing))//проверка на правильность очередности хода
		cout<<"Должен ходить игрок, играющий белыми."<<endl;
	cout<<"Введите координаты ячейки, которую хотите переместить."<<endl;
	cin>>x>>y;
	x--;
	y--;
	}
	}
	cout<<"Введите координаты ячейки, на которую хотите переместить."<<endl;
	cin>>Px>>Py;
	Px--;
	Py--;
	while(Px<0 || Px>7 || Py<0 || Py>7 ||  field.gameField[Px][Py]!=empty 
		||(variable==1 && field.testEatenChecker(Px,Py, x, y)==false))//проверка условий правильности координат, на которые перемещаем
	{
	if(Px<0 || Px>7 || Py<0 || Py>7)
		cout<<"Ошибка.Выберите другие координаты."<<endl;
	else
	{
	if(field.gameField[Px][Py]!=empty)//проверка на пустоту ячейки
		cout<<"Ячейка, на которую хотите переместить, занята"<<endl;
	else
	{
	if(variable==1 && field.testEatenChecker(Px,Py, x, y)==false)//если шашка совершает второй ход подряд, то вторым ходом она должна "съесть" шаку противника
		cout<<"Вторым ходом надо 'съесть' шашку соперника."<<endl;
	}
	}
	cout<<"Введите координаты ячейки, на которую хотите переместить."<<endl;
	cin>>Px>>Py;
	Px--;
	Py--;
	}
	variable=0;//обнуляем переменную
	if((player.isWhiteTurn==true && field.gameField[x][y]==whiteShashka ) || (player.isWhiteTurn==false && field.gameField[x][y]==blackShashka))//если сейчас должен ходить игрок, играющий белыми(черными), и шашка выбрана так же белая(черная)
	{
		checker.x=x;
		checker.y=y;
		if ((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==true))//если на ячейке белая(черная) шашка и возможен ход ее на заданную ячейку
		{
			if(field.permutation(Px,Py,checker.x, checker.y)==true)//проверка функции на просто ход шашки(то есть шашка не "съедает" шашку противника)
		{
			field.transformKing();//проверка:не станет ли шашка дамкой
			field.print();//вывод поля
			player.isWhiteTurn=!player.isWhiteTurn;//передача хода другому игроку
			}
			if(field.testEatenChecker(Px,Py,checker.x, checker.y)==true)//если шашка может "съесть" шашку противника
			{
			field.eatenChecker(Px,Py,checker.x, checker.y);//производим нужные преобразования с полем
			field.transformKing();//проверка:не станет ли шашка дамкой
			field.print();//вывод поля
			if(field.secondCourse(Px,Py)==false)//если невозможен второй ход
				player.isWhiteTurn=!player.isWhiteTurn;//передача хода другому игроку
			else
			variable=1;//в обратном случае присваиваем переменной значение 1
			}
			/*if(field.permutation(Px,Py,checker.x, checker.y)==false && field.testEatenChecker(Px,Py,checker.x, checker.y)==false)//если предыдущие пункты не выполняются
				cout<<"Такой ход невозможен для данной шашки."<<endl;*/
		}
		if((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==false))
			cout<<"Такой ход невозможен для данной шашки."<<endl;
		}
	if((player.isWhiteTurn==true && field.gameField[x][y]==whiteKing ) || (player.isWhiteTurn==false && field.gameField[x][y]==blackKing))//если сейчас должен ходить игрок, играющий белыми(черными), и дамка выбрана так же белая(черная)
		{
		king.x=x;
		king.y=y;
		if ((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==true) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==true))//если на ячейке белая(черная) дамка и возможен ход ее на заданную ячейку
		{
			if(field.permutation(Px,Py,king.x, king.y)==true)//проверка функции на просто ход дамки(то есть дамка не "съедает" шашку противника)
			{
			field.print();//вывод поля
			player.isWhiteTurn=!player.isWhiteTurn;//передача хода другому игроку
			}
			if(field.testEatenChecker(Px,Py,king.x, king.y)==true)//если дамка может "съесть" шашку противника
			{
				field.eatenChecker(Px,Py,king.x, king.y);//производим нужные преобразования с полем
				field.print();//вывод поля
				if(field.secondCourse(Px,Py)==false)//если невозможен второй ход
					player.isWhiteTurn=!player.isWhiteTurn;//передача хода другому игроку
				else
				variable=1;//в обратном случае присваиваем переменной значение 1
			}
			/*if(field.permutation(Px,Py,king.x, king.y)==false && field.testEatenChecker(Px,Py,king.x, king.y)==false)//если предыдущие пункты не выполняются
					cout<<"Такой ход невозможен для данной дамки."<<endl;*/
		}
		if((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==false))
			cout<<"Такой ход невозможен для данной дамки."<<endl;
		}
	if(field.endOfGame()==1)//проверка завершения игры. Если на поле нет черных шашек
	{
		cout<<"Выиграл игрок,играющий белыми."<<endl;
		player.winner=white;
	}
	if(field.endOfGame()==2)//если на поле нет черных шашек
	{
		cout<<"Выиграл игрок,играющий черными."<<endl;
		player.winner=black;
	}
	if(field.endOfGame()==0)//если есть и черные, и белые шашки
	player.winner=blank;
	}
	return 1;
}