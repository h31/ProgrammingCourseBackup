#include "savedgames.h"
#include <QFile>
#include <QTextStream>
SavedGames::SavedGames(void)
{
}
//Сохранение сгенерированного поля
void SavedGames::SaveReadyField(Field* GameField, char name[])
{
    QFile file("C:\\QtProjects\\SUDOKU\\CurrentGameField.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->GameField[ ixRow ][ ixCol ];
            out << " ";
        }
        out << "\n";
    }
    out << "\n";
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
            out << GameField->FieldVictory[ ixRow ][ ixCol ] << " ";
        out << "\n";
    }
    out << "\n";
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->GraphicField[ ixRow ][ ixCol ];
            out << " ";
        }
        out << "\n";
    }
    file.close();
}
//Запрос на сохранение игры
void SavedGames::SaveRequest(Field* GameField)
{
    RecordData("C:\\QtProjects\\SUDOKU\\game.txt", GameField);
}
//Запись текущей игры
void SavedGames::RecordData(char name[], Field* GameField)
{
    QFile file(name);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    /*if (!out)
    {
        cout << "Файл не открывается!\n";
    }*/
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->GameField[ ixRow ][ ixCol ];
            out << " ";
        }
        out << "\n";
    }
    out << "\n";
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->FieldVictory[ ixRow ][ ixCol ];
            out << " ";
        }
        out << "\n";
    }
    out << "\n";
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->GraphicField[ ixRow ][ ixCol ];
            out << " ";
        }
        out << "\n";
    }
    file.close();
}
//Запрос на загрузку игры
void SavedGames::LoadRequest(Field* GameField)
{
    LoadGame("C:\\QtProjects\\SUDOKU\\game.txt", GameField);
}
//Загрузка сохранённой игры
void SavedGames::LoadGame(char name[], Field* GameField)
{
    QFile infile(name);
    infile.open(QIODevice::ReadOnly);
    QTextStream in(&infile);
    QFile outfile("C:\\QtProjects\\SUDOKU\\CurrentGameField.txt");
    outfile.open(QIODevice::ReadOnly, QIODevice::WriteOnly);
    QTextStream out(&outfile);
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            in >> GameField->GameField[ ixRow ][ ixCol ];
            out << GameField->GameField[ ixRow ][ixCol];
            out << " ";
        }
        out << "\n";
    }
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            in >> GameField->FieldVictory[ ixRow ][ ixCol ];
            out << GameField->FieldVictory[ ixRow ][ixCol];
            out << " ";
        }
        out << "\n";
    }
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            in >> GameField->GraphicField[ ixRow ][ ixCol ];
            out << GameField->GraphicField[ ixRow ][ ixCol ];
            out << " ";
        }
        out << "\n";
    }
    infile.close();
    outfile.close();
}
SavedGames::~SavedGames(void)
{
}
