#ifndef FIELD_H
#define FIELD_H

#include <stdlib.h>
class Field
{
    void InitField();
    void Generation(int chislo);
    int IsSq(int ixRow, int ixCol, int chislo);
    int IsVer(int ixRow, int chislo);
    int IsHor(int ixCol, int chislo);
public:
    //����������� ���������
    struct Graphics
    {
        int point_x;//��������� ���������� ������ ������
        int point_y;//���������� ���������� ������ ������
        int p_x;//��������� ���������� ������ ������
        int p_y;//���������� ���������� ������ ������
    };
    int xx;
    int yy;
    int* *FieldVictory;//���� ��� �������� �� ������
    int* *GameField;//������� ����

    Graphics parameters[ 9 ][ 9 ];//������ ����������� ������

    Field(void);
    int CountZero();
    void Fill_Zero(int NumberOfZero);
    void Fill_Zero_Square(int a, int b, int NumberOfZero);
    void InsertChislo(int ixRow, int ixCol, int chislo);
    int CountOfMistakes();
    bool ControlOfChisel(int ixRow, int ixCol);
    ~Field(void);
    int GetCell(int ixRow, int ixCol);
    bool Define_Victory();
    void Graphic_Parameters(int ixRow, int ixCol, int point_1, int point_2, int p_1, int p_2);
};

#endif // FIELD_H
