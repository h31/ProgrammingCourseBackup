#include "savedgames.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "field.h"
using namespace std;
SavedGames::SavedGames()
{
}
//Сохранение сгенерированного поля
void SavedGames::SaveReadyField(Field* GameField, char name[])
{
    ofstream out("CurrentGameField.txt");
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
            out << GameField->FieldVictory[ ixRow ][ ixCol ] << " ";
        out << "\n";
    }
}
//Запрос на сохранения игры
void SavedGames::SaveRequest(Field* GameField)
{
    SaveNameLastGame("game.txt");
    RecordData("game.txt", GameField);
}
//Сохранение имени последней игры
void SavedGames::SaveNameLastGame(char name[])
{
    ofstream out("LastSave.txt");
    if (!out)
    {
        cout << "Файл не открывается!\n";
    }
    out << name;
}
//Запись текущей игры
void SavedGames::RecordData(char name[], Field* GameField)
{
    ofstream out(name);
    if (!out)
        cout << "\n";
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->GameField[ ixRow ][ ixCol ];
            out << " ";
        }
    }
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            out << GameField->FieldVictory[ ixRow ][ ixCol ];
            out << " ";
        }
    }
}
//Запрос на загрузку игры
void SavedGames::LoadRequest(Field* GameField)
{
    ifstream in("LastSave.txt");
    if (!in)
    {
        cout << "Файл не открывается!\n";
        return;
    }
    char name[ 20 ];
    in >> name;
    LoadGame(name, GameField);
}
//Загрузка сохранённой игры
void SavedGames::LoadGame(char name[], Field* GameField)
{
    ifstream in(name);
    if (!in)
    {
        cout << "Файл не открылся!\n";
        return;
    }
    ofstream out("CurrentGameField.txt");
    if (!out)
    {
        cout << "Файл не открылся!\n";
        return;
    }
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            in >> GameField->GameField[ ixRow ][ ixCol ];
        }
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
}
SavedGames::~SavedGames(void)
{
}
