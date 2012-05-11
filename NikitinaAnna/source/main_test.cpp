#include <iostream>
using namespace std;
#include"shashki.h"
#include"field.h"
#include"player.h"
#include"game.h"
#include<locale.h>

int main(void)
{
	Field field;
	Player player;
	Game game;
	Checker checker;
	King king;
	field.fieldMake();
	for(int i=0;i<size;i++)//выводим поле на экран
	{
		for(int j=0;j<size;j++)
			cout<<field.gameField[i][j];
		cout<<endl;
	}
	cout<<endl;
	setlocale(LC_ALL, "Russian");
	checker.x=2; checker.y=3;//Проверка ходов шашки
	if(checker.makeMove1(4,5)==true)
		cout<<"Шашка правильно съедает шашку противника"<<endl;
	else
		cout<<"Шашка НЕправильно съедает шашку противника"<<endl;
	if(checker.makeMove1(3,2)==true)
		cout<<"Шашка правильно совершает обычный ход"<<endl;
	else
		cout<<"Шашка НЕправильно совершает обычный ход"<<endl;
	king.x=2; king.y=3;//Проверка ходов дамки
	if(king.makeMove1(6,7)==true)
		cout<<"Дамка правильно съедает шашку противника"<<endl;
	else
		cout<<"Дамка НЕправильно съедает шашку противника"<<endl;
	if(checker.makeMove1(0,1)==true)
		cout<<"Дамка правильно совершает обычный ход"<<endl;
	else
		cout<<"Дамка НЕправильно совершает обычный ход"<<endl;
	if(player.permutation(3,2,2, 1,field)==true)
		cout<<"Обычный ход белой фигуры совершается правильно, поле преобразуется"<<endl;
	else
		cout<<"Обычный ход белой фигуры совершается НЕправильно, поле НЕ преобразуется"<<endl;
	if(player.permutation(4,1,5, 0,field)==true)
			cout<<"Обычный ход черной фигуры совершается правильно, поле преобразуется"<<endl;
	else
		cout<<"Обычный ход черной фигуры совершается НЕправильно, поле НЕ преобразуется"<<endl;
	if(player.testEatenChecker(5,0, 3, 2,field)==true)
	{
			cout<<"Белая шашка правильно съедает фигуру противника, поле преобразуется"<<endl;
			player.eatenChecker(5,0, 3, 2,field);
	}
	else
		cout<<"Белая шашка НЕправильно съедает фигуру противника, поле НЕ преобразуется"<<endl;
	if(player.secondCourse(5,0,field )==true)
		cout<<"Второй ход шашки правильно найден"<<endl;
	else
		cout<<"Второй ход шашки НЕправильно найден"<<endl;
	if(player.testEatenChecker(7,2,5,0,field)==true)
		player.eatenChecker(7,2, 5, 0,field);
	field.transformKing();
	if(field.gameField[7][2]==whiteKing)
		cout<<"Превращение шашки в дамку произошло успешно"<<endl;
	else
		cout<<"Превращение шашки в дамку НЕ произошло успешно"<<endl;
	field.endOfGame();
	game.findWinner(field);
	if(game.winner=white)
		cout<<"Выиграл игрок,играющий белыми.Все верно."<<endl;
	else
		cout<<"Победитель найден НЕверно"<<endl;
	return 0;
}
	

