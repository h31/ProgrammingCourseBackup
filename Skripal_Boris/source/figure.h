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
};

#endif