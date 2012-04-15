#pragma once

class Field
{
	int* *FieldVictory;//Поле для проверки на ошибки
	void InitField();
	int IsSq(int ixRow, int ixCol, int chislo);
	int IsVer(int ixRow, int chislo);
	int IsHor(int ixCol, int chislo);
public:
	int* *GameField;
	Field(void);
	void Generation(int chislo);
	int CountZero();
	void OutOfField();
	void Fill_Zero(int NumberOfZero);
	void Fill_Zero_Square(int a, int b, int NumberOfZero);
	~Field(void);
	int GetCell(int ixRow, int ixCol);
	void OutOfCell(int ixRow, int ixCol);
	int Define_Victory(char name[]);
};
