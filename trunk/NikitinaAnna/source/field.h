#ifndef _field_h_
#define _field_h_
enum Cell
{
		 empty=0,
		 whiteShashka=1,
		 blackShashka=2,
		 whiteKing=8,
		 blackKing=9
};
class Field
	{
	 Cell gameField[8][8];
	 Field( );
	 ~Field();
	 public:
	 void print();//Вывод поля
	 void permutation(int Px,int Py, int x, int y);//Реализация хода
	 void transformKing();//Превращение шашки в дамку
};

# endif