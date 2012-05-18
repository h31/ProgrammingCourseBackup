#include "game.h"
using namespace std;
Games::Games(void)
{
    srand((unsigned)time(0));
    int chislo = rand()%9+1;
    char name[ 100 ] = "CurrentGameField.txt";
    GameField = new Field;
    SavedGame = new SavedGames();
    SavedGame->SaveReadyField(GameField, name);
}
Games::~Games(void)
{
    delete[] GameField;
    delete[] SavedGame;
}
//Игровое меню
void Games::Menu()
{
    cout << "Игровое меню: \n";
    cout << "1. Играть\n";
    cout << "2. Продолжить\n";
    cout << "3. Выйти\n";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        StartGame();
        PlayGame();
        EndGame();
    }
    else if (choice == 2)
    {
        int choice = 1;
        SavedGame->LoadRequest(GameField);
        OutOfField();
        PlayGame();
        EndGame();
    }
    else if (choice == 3)
    {
        exit(0);
    }
}
//Выбор уровня сложности
int Games::GameLevel(int choice)
{
    int NumberOfZero = 0;
    if (choice == 1)
    {
        NumberOfZero = 4;
        return NumberOfZero;
    }
    else if (choice == 2)
    {
        NumberOfZero = 5;
        return NumberOfZero;
    }
    else if (choice == 3)
    {
        NumberOfZero = 6;
        return NumberOfZero;
    }
}
//Начало игры
void Games::StartGame()
{
    int CountZero = GameLevel(1);
    GameField->Fill_Zero(CountZero);
    OutOfField();
}
//Игровой ход
void Games::GameStep()
{
    cout << "Введите координаты и значение, которое вы хотите вставить: \n";
    int ixRow = 0;
    int ixCol = 0;
    int chislo = 0;
    cin >> ixRow >> ixCol >> chislo;
    ixRow--;
    ixCol--;
    GameField->InsertChislo(ixRow, ixCol, chislo);
    OutOfField();
}
//Проверка поля на ошибки
void Games::ControlField()
{
    cout << "Вы желаете проверить текущую игру? \n";
    cout << "1. Да\n";
    cout << "2. Нет\n";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        int count = 0;
        cout << "Есть ошибка в клетках с координатами: \n";
        for (int ixRow = 0; ixRow < 9; ixRow++)
        {
            for (int ixCol = 0; ixCol < 9; ixCol++)
            {
                bool Control = GameField->ControlOfChisel(ixRow, ixCol);
                if (Control == 1)
                {
                    int Row = GameField->xx;
                    int Col = GameField->yy;
                    Row++;
                    Col++;
                    cout << Row << " " << Col << "\n";
                }
            }
        }
    }
}
//Игра
void Games::PlayGame()
{
    int count = GameField->CountZero();
    do
    {
        GameStep();
        int choice = 0;
        cout << "Вы желаете сохранить текущую игру?\n";
        cout << "1.Да\n";
        cout << "2.Нет\n";
        cin >> choice;
        SavedGame->SaveRequest(GameField);
        ControlField();
        count--;
    } while(count != 0);
}
//Конец игры
void Games::EndGame()
{
    int count = 0;
    bool victory = GameField->Define_Victory();
    if (victory == 1)
        cout << "Вы выиграли!\n";
    else if (victory == 0)
    {
        cout << "Есть ошибка в клетке с координатами: " << "\n";
        for (int ixRow = 0; ixRow < 9; ixRow++)
        {
            for (int ixCol = 0; ixCol < 9; ixCol++)
            {
                GameField->ControlOfChisel(ixRow, ixCol);
                int Row = GameField->xx;
                int Col = GameField->yy;
                Row++;
                Col++;
                cout << Row << " " << Col << "\n";
            }
        }
        count = GameField->CountOfMistakes();
        do
        {
            GameStep();
            int choice = 0;
            cout << "Вы желаете сохранить текущую игру?\n";
            cout << "1.Да\n";
            cout << "2.Нет\n";
            cin >> choice;
            SavedGame->SaveRequest(GameField);
            ControlField();
            count--;
        } while(count != 0);
    }
    OutOfField();
    int choice = 0;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cin >> choice;
    SavedGame->LoadRequest(GameField);
    OutOfField();
}
//Вывод поля
void Games::OutOfField()
{
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            cout << " " << GameField->GameField[ ixRow ][ ixCol ] << " ";
        }
        cout << "(" << ixRow+1 << ")\n\n";
    }
    for (int ixRow = 0; ixRow < 9; ixRow++)
        cout << "(" << ixRow+1 << ")";
    cout << "\n";
}
