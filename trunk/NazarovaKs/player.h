#ifndef _player_h_
#define _player_h_

#include <iostream>
#include <time.h>

using namespace std;
// Условимся, что поле с числами - это некая матрица с числами, тогда имеем:
const unsigned short maxColumns=7; // - максимальное количество столбцов в матрице;
const unsigned short maxCells=343; // - предел числа ячеек в матрице (некая защита от "идиота").
// Строим класс под названием - "Игрок" (см. ниже "Player").
// В моем понимании, класс "Игрок" - базовый класс, тк для него все это и нужно.
// А именно, для игрока строится матрица, в дальнейшем - заполняется, и именно
// ему предлагается проявить смекалку в решении ее (в данном случае, удалить как можно больше чисел).
class Player {
// В классе "Игрок" мы имеем:
private:
	// - начальное кол-во строк;
	unsigned short rows;
	// - структуру - "Ячейка" (в идее это одна строка матрицы) - несет в себе неплохие функциональные особенности. 
	// В частности, это построение двунаправленного списка (для более удобного посроения операций со строками в матрице).
	struct Cell {
		// В "Ячейке" у нас заключено:
		// - указатели: предыдущии/следующий (для связи строк);
		Cell *prev, *next;
		// - массив данных в ондой строке.
		unsigned short data[maxColumns];

		Cell(); // конструктор "по-умолчанию" - для построения элементарной строки
		Cell( unsigned short ); //конструктор с параметром - для заполнения ячейки
		~Cell() {} // деструктор - не описан, тк не используем динамическую память
		friend ostream& operator << (ostream& out, const Cell& cell){
			for(unsigned short i=0; i<maxColumns; i++)
				out<<cell.data[i]<<" ";
			out<<endl;
			return out;
		}
	};
public:
	Cell* firstCell; // указатель на первую ячейку (строку) в нашей матрице
	Player(); // конструктор "по-умолчанию" - конструирует 0 ячеек 
	Player(unsigned short amtRows);
	~Player() {};
	//Cell* makeCell();
	//Cell* makeList();

	friend ostream& operator << (ostream& out, const Player& );
	//void output (Cell* start);
};

void createField();

#endif