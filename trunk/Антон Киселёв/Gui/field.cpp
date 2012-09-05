#include "field.h"
using namespace std;
Field::Field()
{
    GameField = new int *[ 9 ];
    for (int i = 0; i < 9; i++)
        GameField[ i ] = new int [ 9 ];
    FieldVictory = new int *[ 9 ];
    for (int i = 0; i < 9; i++)
        FieldVictory[ i ] = new int [ 9 ];
    InitField();
    int chislo = 3;
    Generation(chislo);
    for (int ixRow = 0; ixRow < 9; ixRow++)
        for (int ixCol = 0; ixCol < 9; ixCol++)
            FieldVictory[ ixRow ][ ixCol ] = GameField[ ixRow ][ ixCol ];
}
//Заполнение массива готовым образцом
void Field::InitField()
{
    for (int ixRow = 0; ixRow < 9; ixRow++)
        for (int ixCol = 0; ixCol < 9; ixCol++)
            GameField[ ixRow ][ ixCol ] = -1;
}
//Генерация полного поля
void Field::Generation(int chislo)
{
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
                int count = 9;
                for (int var = 1; var < 10; ++var)
                {
                    if (IsSq(ixRow, ixCol, var) || IsHor(ixCol, var) || IsVer(ixRow, var))
                        --count;
                }
                if (!count)
                {
                    InitField();
                    Generation(chislo);
                    return;
                }
                while (IsSq(ixRow, ixCol, chislo) || IsHor(ixCol, chislo) || IsVer(ixRow, chislo))
                    chislo = rand()%9+1;
                GameField[ ixRow ][ ixCol ] = chislo;
        }
    }
}
//Определение количества пропусков
int Field::CountZero()
{
    int count = 0;
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (GameField[ ixRow ][ ixCol ] == 0)
                count++;
        }
    }
    return count;
}
//Заполнение пропусками
void Field::Fill_Zero(int NumberOfZero)
{
    Fill_Zero_Square(0, 0, NumberOfZero);
    Fill_Zero_Square(0, 3, NumberOfZero);
    Fill_Zero_Square(0, 6, NumberOfZero);
    Fill_Zero_Square(3, 0, NumberOfZero);
    Fill_Zero_Square(3, 3, NumberOfZero);
    Fill_Zero_Square(3, 6, NumberOfZero);
    Fill_Zero_Square(6, 0, NumberOfZero);
    Fill_Zero_Square(6, 3, NumberOfZero);
    Fill_Zero_Square(6, 6, NumberOfZero);
}
//Заполнение каждого отдельного квадрата 3 на 3 пропусками
void Field::Fill_Zero_Square(int a, int b, int NumberOfZero)
{
    for (int i = 0; i < NumberOfZero; i++)
    {
        int ixRow = rand()%3+a;
        int ixCol = rand()%3+b;
        GameField[ ixRow ][ ixCol ] = 0;
    }
}
//Проверка по квадрату
int Field::IsSq(int ixRow, int ixCol, int chislo)
{
    int SqIxRow = ixRow/3;
    int SqIxCol = ixCol/3;
    for (int _b(SqIxRow*3), ddi = _b; ddi < _b+3; ++ddi)
        for (int __b(SqIxCol*3), ddj = __b; ddj < __b+3; ++ddj)
            if (GameField[ ddi ][ ddj ] == chislo)
                return 1;
    return 0;
}
//Проверка по столбцу
int Field::IsVer(int ixRow, int chislo)
{
    for (int SqIxCol = 0; SqIxCol < 9; ++SqIxCol)
        if (GameField[ ixRow ][ SqIxCol ] == chislo)
            return 1;
    return 0;
}
//Проверка по строке
int Field::IsHor(int ixCol, int chislo)
{
    for (int SqIxRow = 0; SqIxRow < 9; ++SqIxRow)
        if (GameField[ SqIxRow ][ ixCol ] == chislo)
            return 1;
    return 0;
}
//Подсчет количества ошибок в поле
int Field::CountOfMistakes()
{
    int count = 0;
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (GameField[ ixRow ][ ixCol ] != FieldVictory[ ixRow ][ ixCol ])
            {
                count++;
            }
        }
    }
    return count;
}
//Проверка чисел
bool Field::ControlOfChisel(int ixRow, int ixCol)
{
    if (GameField[ ixRow ][ ixCol ] != FieldVictory[ ixRow ][ ixCol ])
    {
        xx = ixRow;
        yy = ixCol;
        return 1;
    }
    else
    {
        return 0;
    }
}
//Определение победы игрока
bool Field::Define_Victory()
{
    int count = CountOfMistakes();
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Возврат значения в клетке
int Field::GetCell(int ixRow, int ixCol)
{
    return GameField[ ixRow ][ ixCol ];
}
//Вставка значения
void Field::InsertChislo(int ixRow, int ixCol, int chislo)
{
    GameField[ ixRow ][ ixCol ] = chislo;
}
//Записываем графические параметры для каждой клетки игрового поля
void Field::Graphic_Parameters(int ixRow, int ixCol, int point_1, int point_2, int p_1, int p_2)
{
    parameters[ ixRow ][ ixCol ].point_x = point_1;
    parameters[ ixRow ][ ixCol ].point_y = point_2;
    parameters[ ixRow ][ ixCol ].p_x = p_1;
    parameters[ ixRow ][ ixCol ].p_y = p_2;
}
//Создание поля для определения цвета клетки
void Field::CreateGraphicField()
{
    GraphicField = new int * [ 9 ];
    for (int i = 0; i < 9; i++)
        GraphicField[ i ] = new int [ 9 ];
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (GameField[ ixRow ][ ixCol ] == 0)
                GraphicField[ ixRow ][ ixCol ] = 0;
            else if (GameField[ ixRow ][ ixCol ] != 0)
                GraphicField[ ixRow ][ ixCol ] = 1;
        }
    }
}
//Взятие значения из графического поля
int Field::CellGraphicField(int ixRow, int ixCol)
{
    return GraphicField[ ixRow ][ ixCol ];
}
//Поиск повторов
//По строке
bool Field::SearchRepeatsRow(int ixRow, int ixCol)
{
    for (int SqIxCol = 0; SqIxCol < ixCol; ++SqIxCol)
    {
        if (GameField[ ixRow ][ SqIxCol ] == GameField[ ixRow ][ ixCol ])
        {
            x = ixRow;
            y = SqIxCol;
            return true;
        }
    }
    for (int SqIxCol = ixCol+1; SqIxCol < 9; SqIxCol++)
    {
        if (GameField[ ixRow ][ SqIxCol ] == GameField[ ixRow ][ ixCol ])
        {
            x = ixRow;
            y = SqIxCol;
            return true;
        }
    }
    return false;
}
//По столбцу
bool Field::SearchRepeatsCol(int ixRow, int ixCol)
{
    for (int SqIxRow = 0; SqIxRow < ixRow; ++SqIxRow)
    {
        if (GameField[ SqIxRow ][ ixCol ] == GameField[ ixRow ][ ixCol ])
        {
            x = SqIxRow;
            y = ixCol;
            return true;
        }
    }
    for (int SqIxRow = ixRow+1; SqIxRow < 9; SqIxRow++)
    {
        if (GameField[ SqIxRow ][ ixCol ] == GameField[ ixRow ][ ixCol ])
        {
            x = SqIxRow;
            y = ixCol;
            return true;
        }
    }
    return false;
}
//По квадрату
void Field::SearchRepeatsSq(int ixRow, int ixCol)
{
    for (int i = 0; i < 9; i++)
    {
        mass_x[ i ] = 10;
        mass_y[ i ] = 10;
    }
    int SqIxRow = ixRow/3;
    int SqIxCol = ixCol/3;
    int ddi = 0;
    int ddj = 0;
    int _b = SqIxRow*3;
    int __b = SqIxCol*3;
    int i = 0;
    int j = 0;
    for (ddi = _b; ddi < _b+3; ddi++)
    {
        for (ddj = __b; ddj < __b+3; ddj++)
        {
            if (GameField[ ddi ][ ddj ] == GameField[ ixRow ][ ixCol ])
            {
                x = ddi;
                y = ddj;
                mass_x[ i ] = x;
                mass_y[ j ] = y;
                i++;
                j++;
            }
        }
    }
}
Field::~Field(void)
{
}
