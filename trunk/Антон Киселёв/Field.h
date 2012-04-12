#pragma once

class Field
{
	void InitField();
	void Generation(int chislo);
	void Fill_Zero();
	int IsSq(int ixRow, int ixCol, int chislo);
	int IsVer(int ixRow, int chislo);
	int IsHor(int ixCol, int chislo);
protected:
	int* *GameField;
public:
	Field(void);
	void OutOfField();
	~Field(void);
	int GetCell(int ixRow, int ixCol);
	void OutOfCell(int ixRow, int ixCol);
};
