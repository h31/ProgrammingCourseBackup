#pragma once

class Field
{
public:
	int** GameField;

	Field(void);
	int IsSq(int ixRow, int ixCol, int chislo);
	int IsVer(int ixRow, int chislo);
	int IsHor(int ixCol, int chislo);
	void InitMas();
	void Sudoku(int chislo);
	void Fill_Zero(int G);
	void ShowMas();
	~Field(void);
};