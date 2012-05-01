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
	 Field();
	 ~Field();
	 Cell gameField[size][size];//игровое поле
	void fieldMake();//заполнение поля
	 void print();//Вывод поля
	 bool permutation(int Px,int Py, int x, int y);//Реализация обычного хода
	 void eatenChecker(int Px,int Py, int x, int y);//Реализация хода при съедении шашки врага
	 bool secondCourse(int Px,int Py);//Реализация следующего хода той же шашки после того, как она "съела" шашку противника
	 void transformKing();//Превращение шашки в дамку
	 int endOfGame();//Проверка окончания игры
	 bool testEatenChecker(int Px,int Py, int x, int y);//Проверка:возможно ли данной шашке или дамке "съесть" шашку противника
};

# endif