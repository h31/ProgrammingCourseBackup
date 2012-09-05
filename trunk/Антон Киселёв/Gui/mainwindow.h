#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLayout>
#include <QEvent>
#include "savedgames.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //Игровое меню:
    QMenu *Game;//Меню игры

    QAction *newGameAction;//Новая игра
    QAction *loadGame;//Загразка игры
    QAction *saveAction;//Сохранение игры
    QAction *checkingAction;//Проверка поля на ошибки
    QAction *exitAction;//Выход из игры
    QAction *includeTips;//Включение подсказок
    QAction *switchoffTips;//Выключение подсказок

    QMenuBar *bar;//Меню-бар
public:
    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();
    //Флаги событий
    bool is_New_Game_Activated;//Новая игра
    bool is_Load_Game_Activated;//Загрузка игры
    bool is_Mouse_Clicked;//Нажатие мыши
    bool is_Checking;//Проверка поля на ошибки
    bool is_Keyboard_activated;//Клавиатура

    int tips;//Подсказки

    Field* GameField;//Игровое поле
    SavedGames *save_game;//Сохранение/загрузка игр

    //Окно уровня сложности
    QPushButton *easy, *normal, *hard;
    QGridLayout *lay, *savelay;
    //Окно сохранения игры
    QPushButton *save, *cancel;
    SavedGames* SaveGame;

    QDialog* leveldialog;
    QDialog* savedialog;

    QPainter* painter;

    //Определение координаты клетки
    int defined_ixRow;
    int defined_ixCol;
    //Графическое поле
    void paintEvent(QPaintEvent *);
    void DrawPole(QPen &pen, int &pointIxRow, int &pointIxCol);//Рисование первоначального поля
    void DrawCells();//Рисование клеток
    void DrawText(int &p1, int &p2);//Вставка текста
    void DrawEvent();//Рисование события мыши
    //Мышь
    void mousePressEvent(QMouseEvent * ev);
    void PaintTips(int &ixRow, int &ixCol);
    void insert_in_cell(int ixRow, int ixCol);
    void CreateNewGame(int choice);
    void Save_Graphic_Options();
    void Paint_Mistakes();
    void Define_Victory();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void CreateActions();
    void CreateMenu();

private slots:
    void SaveDialog();
    void LoadGame();
    void Checking();
    void ChoiceLevel();
    void firstlevel();
    void secondlevel();
    void thirdlevel();
    void save_pressed();
    void cancel_press();
    void Include_Tips();
    void Switch_off_Tips();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
};

#endif // MAINWINDOW_H
