#include <iostream>
#include <fstream>
#include <locale.h>
#include <time.h>
#include "Field.h"
#include "Cell.h"
using namespace std;
void main(void)
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));
	Field GameField;
	GameField.OutOfField();
	int chislo = 0;
	int ixRow = 0;
	int ixCol = 0;
	chislo = GameField.GetCell(ixRow, ixCol);
	cout << chislo << "\n";
	for (int ixRow = 0; ixRow < 9; ixRow++)
	{
		for (int ixCol = 0; ixCol < 9; ixCol++)
		{
			GameField.OutOfCell(ixRow, ixCol);
		}
		cout << "\n\n";
	}
}