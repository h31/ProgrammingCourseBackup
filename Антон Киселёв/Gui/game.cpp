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
//������� ����
void Games::Menu()
{
    cout << "������� ����: \n";
    cout << "1. ������\n";
    cout << "2. ����������\n";
    cout << "3. �����\n";
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
//����� ������ ���������
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
//������ ����
void Games::StartGame()
{
    int CountZero = GameLevel(1);
    GameField->Fill_Zero(CountZero);
    OutOfField();
}
//������� ���
void Games::GameStep()
{
    cout << "������� ���������� � ��������, ������� �� ������ ��������: \n";
    int ixRow = 0;
    int ixCol = 0;
    int chislo = 0;
    cin >> ixRow >> ixCol >> chislo;
    ixRow--;
    ixCol--;
    GameField->InsertChislo(ixRow, ixCol, chislo);
    OutOfField();
}
//�������� ���� �� ������
void Games::ControlField()
{
    cout << "�� ������� ��������� ������� ����? \n";
    cout << "1. ��\n";
    cout << "2. ���\n";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        int count = 0;
        cout << "���� ������ � ������� � ������������: \n";
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
//����
void Games::PlayGame()
{
    int count = GameField->CountZero();
    do
    {
        GameStep();
        int choice = 0;
        cout << "�� ������� ��������� ������� ����?\n";
        cout << "1.��\n";
        cout << "2.���\n";
        cin >> choice;
        SavedGame->SaveRequest(GameField);
        ControlField();
        count--;
    } while(count != 0);
}
//����� ����
void Games::EndGame()
{
    int count = 0;
    bool victory = GameField->Define_Victory();
    if (victory == 1)
        cout << "�� ��������!\n";
    else if (victory == 0)
    {
        cout << "���� ������ � ������ � ������������: " << "\n";
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
            cout << "�� ������� ��������� ������� ����?\n";
            cout << "1.��\n";
            cout << "2.���\n";
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
//����� ����
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
