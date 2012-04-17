#pragma once

class Field
{
	void InitField();
	void Generation(int chislo);
	int IsSq(int ixRow, int ixCol, int chislo);
	int IsVer(int ixRow, int chislo);
	int IsHor(int ixCol, int chislo);
public:
	int* *FieldVictory;//Поле для проверки на ошибки
	int* *GameField;
	Field(int chislo, char name[]);
	int CountZero();
	void OutOfField();
	void Fill_Zero(int NumberOfZero);
	void Fill_Zero_Square(int a, int b, int NumberOfZero);
	~Field(void);
	int GetCell(int ixRow, int ixCol);
	void OutOfCell(int ixRow, int ixCol);
	int Define_Victory(char name[]);
};
