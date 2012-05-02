#pragma once

class Field
{
	void InitField();
	void Generation(int chislo);
	int IsSq(int ixRow, int ixCol, int chislo);
	int IsVer(int ixRow, int chislo);
	int IsHor(int ixCol, int chislo);
public:
	int xx;//������
	int yy;//�������
	int* *FieldVictory;//���� ��� �������� �� ������
	int* *GameField;//
	Field(int chislo);
	int CountZero();
	void Fill_Zero(int NumberOfZero);
	void Fill_Zero_Square(int a, int b, int NumberOfZero);
	void InsertChislo(int ixRow, int ixCol, int chislo);
	int CountOfMistakes();
	bool ControlOfChisel(int ixRow, int ixCol);
	~Field(void);
	int GetCell(int ixRow, int ixCol);
	bool Define_Victory();
};
