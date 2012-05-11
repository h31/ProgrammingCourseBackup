#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include"game.h"
#include"console.h"
#include<locale.h>

void Console::print(Field& field)//Вывод поля
{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<field.gameField[i][j];
		cout<<endl;
	}
		cout<<endl;
}
void Console::dialog( int Px,int Py, int variable,Field& field, Player& player, Game& game)
{
	setlocale(LC_ALL, "Russian");
	if( variable==1)//то есть если в предыдущий ход шашка съела шашку противника, и сейчас  возможен второй ход этой же шашки
	{
		conx=Px;cony=Py;//координаты шашки, которую хотим переместить уже определены
		cout<<"Игрок может сходить еще раз и 'съесть' еще одну шашку противника своей шашкой с координатами "<<++conx<<" "<<++cony<<endl;
		conx--;cony--;
	}
	else//в ином случае просим игрока ввести координаты шашки, которую он хочет переместить
	{
	cout<<"Введите координаты ячейки, которую хотите переместить."<<endl;
	cin>>conx>>cony;
	conx--;cony--;
	while((conx<0 || conx>7 || cony<0 || cony>7) || 
		field.gameField[conx][cony]==empty || 
		((game.isWhiteTurn==true && (field.gameField[conx][cony]==blackShashka || field.gameField[conx][cony]==blackKing)) 
		|| (game.isWhiteTurn==false && (field.gameField[conx][cony]==whiteShashka  || field.gameField[conx][cony]==whiteKing))))//проверка условий правильности координат
	{
	if(conx<0 || conx>7 || cony<0 || cony>7)
		cout<<"Ошибка.Выберите другие координаты."<<endl;
	if(conx>=0 && conx<=7 && cony>=0 && cony<=7 &&  field.gameField[conx][cony]==empty)//Проверка на пустоту ячейки.
		cout<<"Ячейка , которую хотите переместить, пуста"<<endl;
	if(conx>=0 && conx<=7 && cony>=0 && cony<=7 &&  field.gameField[conx][cony]!=empty && game.isWhiteTurn==false && (field.gameField[conx][cony]==whiteShashka  || field.gameField[conx][cony]==whiteKing))//проверка на правильность очередности хода
		cout<<"Должен ходить игрок, играющий черными."<<endl;
	if(conx>=0 && conx<=7 && cony>=0 && cony<=7 &&  field.gameField[conx][cony]!=empty && game.isWhiteTurn==true  && (field.gameField[conx][cony]==blackShashka || field.gameField[conx][cony]==blackKing))//проверка на правильность очередности хода
		cout<<"Должен ходить игрок, играющий белыми."<<endl;
	cout<<"Введите координаты ячейки, которую хотите переместить."<<endl;
	cin>>conx>>cony;
	conx--;cony--;
	}
	}
	cout<<"Введите координаты ячейки, на которую хотите переместить."<<endl;
	cin>>conPx>>conPy;
	conPx--;conPy--;
	while(conPx<0 || conPx>7 || conPy<0 || conPy>7 ||  field.gameField[conPx][conPy]!=empty 
		||(variable==1 && player.testEatenChecker(conPx,conPy, conx, cony,field)==false))//проверка условий правильности координат, на которые перемещаем
	{
	if(conPx<0 || conPx>7 || conPy<0 || conPy>7)
		cout<<"Ошибка.Выберите другие координаты."<<endl;
	else
	{
	if(field.gameField[conPx][conPy]!=empty)//проверка на пустоту ячейки
		cout<<"Ячейка, на которую хотите переместить, занята"<<endl;
	else
	{
	if(variable==1 && player.testEatenChecker(conPx,conPy, conx, cony,field)==false)//если шашка совершает второй ход подряд, то вторым ходом она должна "съесть" шаку противника
		cout<<"Вторым ходом надо 'съесть' шашку соперника."<<endl;
	}
	}
	cout<<"Введите координаты ячейки, на которую хотите переместить."<<endl;
	cin>>conPx>>conPy;
	conPx--;conPy--;
	}
	variable=0;//обнуляем переменную
}
void Console::check(Field& field,Checker& checker,King& king,int Px, int Py, int x, int y)
{
	setlocale(LC_ALL, "Russian");
	if((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==false))
			cout<<"Такой ход невозможен для данной шашки."<<endl;
	if((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==false) || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==false))
			cout<<"Такой ход невозможен для данной дамки."<<endl;
}
void Console::printResult(Game& game)
{
	setlocale(LC_ALL, "Russian");
	if(game.winner=white)
		cout<<"Выиграл игрок,играющий белыми."<<endl;
	if(game.winner=black)
		cout<<"Выиграл игрок,играющий черными."<<endl;
}
int Console::getConx()
{
	return conx;
}
int Console::getCony()
{
	return cony;
}
int Console::getConPx()
{
	return conPx;
}
int Console::getConPy()
{
	return conPy;
}