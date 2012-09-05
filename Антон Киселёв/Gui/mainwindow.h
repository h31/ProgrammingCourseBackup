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
    explicit MainWindow(QMainWindow *parent = 0);
    ~MainWindow();
    //����� �������
    bool is_New_Game_Activated;//����� ����
    bool is_Load_Game_Activated;//�������� ����
    bool is_Mouse_Clicked;//������� ����
    bool is_Checking;//�������� ���� �� ������
    bool is_Keyboard_activated;//����������

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
