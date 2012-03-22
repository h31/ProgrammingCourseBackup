#ifndef _figure_h_
#define _figure_h_

enum Type
{
	emptyCell,//Пустая клетка
	elephant,//слон
	horse,//конь
	king,//король
	pawn,//пешка
	queen,//ферзь
	rook//ладья
};

enum CellType
{
	blackCell,//чёрная клетка
	whiteCell//Белая клетка
};

class Figure
{
	//возможность хода пешки
	bool canPawnTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY, const bool whitePlayer);
	//возможность хода короля
	bool canKingTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//возможность хода ладьи
	bool canRookTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//возможность хода ферзя
	bool canQueenTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//возможность хода коня
	bool canHourseTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
	//возможность хода слона
	bool canElephantTurn(Figure ** desk,const int startX,const int startY,const int finishX,const int finishY);
public:
	//цвет фигуры
	bool whiteFigure;
	//цвет клетки
	CellType cellType;
	//тип фигуры
	Type type;
	//количество ходов, сделанных фигурой
	int steps;
	//конструктор
	Figure();
	//оператор присваивания
	Figure& operator = (const Figure& figure);

	friend class Desk;
};

#endif