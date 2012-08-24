#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLayout>
#include <QEvent>
#include "savedgames.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //������� ����:
    QMenu *Game;//���� ����

    QAction *newGameAction;//����� ����
    QAction *loadGame;//�������� ����
    QAction *saveAction;//���������� ����
    QAction *checkingAction;//�������� ���� �� ������
    QAction *exitAction;//����� �� ����
    QAction *includeTips;//��������� ���������
    QAction *switchoffTips;//���������� ���������

    QMenuBar *bar;//����-���
public:
    //����� �������
    bool is_New_Game_Activated;//����� ����
    bool is_Load_Game_Activated;//�������� ����
    bool is_Mouse_Clicked;//������� ����
    bool is_Checking;//�������� ���� �� ������

    int tips;//���������

    Field* GameField;//������� ����
    SavedGames *save_game;//����������/�������� ���

    //���� ������ ���������
    QPushButton *easy, *normal, *hard;
    QGridLayout *lay, *savelay;
    //���� ���������� ����
    QPushButton *save, *cancel;
    SavedGames* SaveGame;

    QDialog* leveldialog;
    QDialog* savedialog;

    QPainter* painter;

    MainWindow();
    ~MainWindow();
    //����������� ���������� ������
    int defined_ixRow;
    int defined_ixCol;
    //����������� ����
    void paintEvent(QPaintEvent *);
    void DrawPole(QPen &pen, int &pointIxRow, int &pointIxCol);//��������� ��������������� ����
    void DrawCells();//��������� ������
    void DrawText(int &p1, int &p2);//������� ������
    void DrawEvent();//��������� ������� ����

    //����
    void mousePressEvent(QMouseEvent * ev);
    void PaintTips(int &ixRow, int &ixCol);
    void insert_in_cell(int ixRow, int ixCol);
    void CreateNewGame(int choice);
    void Save_Graphic_Options();
    void Paint_Mistakes();
    void Define_Victory();

private:
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
};

#endif // MAINWINDOW_H
