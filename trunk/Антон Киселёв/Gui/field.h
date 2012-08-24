#ifndef FIELD_H
#define FIELD_H

#include <stdlib.h>
class Field
{
    /*Формирование массива чисел*/
    void InitField();
    void Generation(int chislo);
    int IsSq(int ixRow, int ixCol, int chislo);
    int IsVer(int ixRow, int chislo);
    int IsHor(int ixCol, int chislo);
public:
    //Графические параметры
    struct Graphics
    {
        int point_x;//Строковая координата начала клетки
        int point_y;//Столбцовая координата начала клетки
        int p_x;//Строковая координата начала текста
        int p_y;//Столбцовая координата начала текста
    };
    //Вспомогательгын переменные
    int xx;
    int yy;

    int x;
    int y;

    int mass_x[ 9 ];//Массив абцисс координат
    int mass_y[ 9 ];//Массив ординат координат

    int h;//Параметр

    int* *GameField;//Игровое поле
    int* *FieldVictory;//Поле для проверки на ошибки
    int* *GraphicField;//Поле для определения цвета клетки

    Graphics parameters[ 9 ][ 9 ];//Массив графических данных

    Field(void);
    int CountZero();//Число нулей
    void Fill_Zero(int NumberOfZero);//Заполнение нулями
    void Fill_Zero_Square(int a, int b, int NumberOfZero);//Заполнение нулями по квадарату
    void InsertChislo(int ixRow, int ixCol, int chislo);//Вставка числа
    int CountOfMistakes();//Определение количества ошибок
    bool ControlOfChisel(int ixRow, int ixCol);
    ~Field(void);
    int GetCell(int ixRow, int ixCol);//Взятие числа из клетки
    bool Define_Victory();//Определение победы
    void Graphic_Parameters(int ixRow, int ixCol, int point_1, int point_2, int p_1, int p_2);//Заполнение графических параметров поля для каждой клетки
    void CreateGraphicField();//Формирование массива для построрения графического поля
    int CellGraphicField(int ixRow ,int ixCol);//Получение клетки графического поля

    bool SearchRepeatsRow(int ixRow, int ixCol);//Поиск повторов по строке
    bool SearchRepeatsCol(int ixRow, int ixCol);//Поиск повторов по столбцу
    void SearchRepeatsSq(int ixRow, int ixCol);//Поиск повтров по квадрату
};
#endif // FIELD_H
