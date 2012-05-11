#ifndef _field_h_
#define _field_h_

 const int size=8;
enum Cell//состояние ячейки
{
		 empty=0,//пуста
		 whiteShashka=1,//белая шашка
		 blackShashka=2,//черная шашка
		 whiteKing=8,//белая дамка
		 blackKing=9//черная дамка
};
class Field
	{
	public:
	int opponentX;
	int opponentY;
	 Field();
	 ~Field();
	 Cell gameField[size][size];//игровое поле
	void fieldMake();//заполнение поля
	 void transformKing();//Превращение шашки в дамку
	 int endOfGame();//Проверка окончания игры
};

# endif