#include "mainwindow.h"
#include "savedgames.h"
#include "windialog.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QtGui>

MainWindow::MainWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateActions();
    CreateMenu();
}
//Действия в меню
void MainWindow::CreateActions()
{
    is_New_Game_Activated = false;
    is_Load_Game_Activated = false;
    is_Mouse_Clicked = false;
    is_Checking = false;
    newGameAction = new QAction("New Game",this);
    connect(newGameAction,SIGNAL(triggered()),this,SLOT(ChoiceLevel()));
    loadGame = new QAction("Load Game", this);
    connect(loadGame, SIGNAL(triggered()),this,SLOT(LoadGame()));
    saveAction = new QAction("Save Game",this);
    connect(saveAction,SIGNAL(triggered()),this,SLOT(SaveDialog()));
    checkingAction = new QAction("Check",this);
    connect(checkingAction,SIGNAL(triggered()),this,SLOT(Checking()));
    exitAction = new QAction("Exit",this);
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    includeTips = new QAction("Tips",this);
    connect(includeTips,SIGNAL(triggered()), this,SLOT(Include_Tips()));
    switchoffTips = new QAction("No Tips",this);
    connect(switchoffTips,SIGNAL(triggered()),this,SLOT(Switch_off_Tips()));
}
//Игровое меню
void MainWindow::CreateMenu()
{
    bar = new QMenuBar(this);
    Game = bar->addMenu("Game");
    Game->addAction(newGameAction);
    Game->addAction(loadGame);
    Game->addSeparator();
    Game->addAction(checkingAction);
    Game->addAction(saveAction);
    Game->addSeparator();
    Game->addAction(includeTips);
    Game->addAction(switchoffTips);
    Game->addSeparator();
    Game->addAction(exitAction);
    this->setMenuBar(bar);
}
//Рисование поля
void MainWindow::DrawPole(QPen &pen, int & pointIxRow, int &pointIxCol)
{
    painter = new QPainter;
    painter->begin(this);
    painter->setPen(pen);
    painter->drawRect(10, 50, 90, 90);
    painter->drawRect(100, 50, 90, 90);
    painter->drawRect(190, 50, 90, 90);
    painter->drawRect(10, 140, 90, 90);
    painter->drawRect(100, 140, 90, 90);
    painter->drawRect(190, 140, 90, 90);
    painter->drawRect(10, 230, 90, 90);
    painter->drawRect(100, 230, 90, 90);
    painter->drawRect(190, 230, 90, 90);

    painter->setBrush(QBrush(Qt::green, Qt::Dense4Pattern));
    painter->setFont(QFont("Times", 20, QFont::Normal));
    pen.setWidth(1);
    painter->setPen(pen);
    for (int ixRow = 0 ; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            painter->setBrush(QBrush(Qt::green, Qt::Dense4Pattern));
            painter->drawRect(pointIxRow, pointIxCol, 30, 30);
            pointIxRow = pointIxRow+30;
        }
        pointIxRow = 10;
        pointIxCol = pointIxCol+30;
    }

}
//Закрашиваем клетки
void MainWindow::DrawCells()
{
    painter->setFont(QFont("Times", 20, QFont::Normal));
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (GameField->CellGraphicField(ixRow, ixCol) == 0)
            {
                painter->setBrush(QBrush(Qt::green, Qt::Dense1Pattern));
                painter->drawRect(GameField->parameters[ ixRow ][ ixCol ].point_x, GameField->parameters[ ixRow ][ ixCol ].point_y, 30, 30);
                if (tips == 1)
                {
                    if ((GameField->GetCell(ixRow, ixCol) != 0) && (GameField->GetCell(ixRow, ixCol) != GameField->FieldVictory[ ixRow ][ ixCol ]))
                        PaintTips(ixRow, ixCol);
                }
            }
            else if (GameField->CellGraphicField(ixRow, ixCol) != 0)
            {
                painter->setBrush(QBrush(Qt::green, Qt::Dense4Pattern));
                painter->drawRect(GameField->parameters[ ixRow ][ ixCol ].point_x, GameField->parameters[ ixRow ][ ixCol ].point_y, 30, 30);
            }
        }
    }
    if (is_Checking == true)
    {
        Paint_Mistakes();
    }
}
//Рисуем текст
void MainWindow::DrawText(int &p1, int &p2)
{
    painter->setFont(QFont("Times", 20, QFont::Normal));
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (GameField->GetCell(ixRow, ixCol) == 0)
            {
                painter->drawText(p1, p2, " ");
            }
            else if (GameField->GetCell(ixRow, ixCol) != 0)
            {
                QString y(QString::number(GameField->GetCell(ixRow, ixCol), 10));
                painter->drawText(p1, p2, y);
            }
            p1 = p1+30;
        }
        p1 = 18;
        p2 = p2+30;
    }
}
//Событие мыши
void MainWindow::DrawEvent()
{
    if (is_Mouse_Clicked == true)
    {
        painter->setBrush(QBrush(Qt::blue, Qt::Dense4Pattern));
        painter->drawRect(GameField->parameters[ defined_ixRow ][ defined_ixCol ].point_x, GameField->parameters[ defined_ixRow ][ defined_ixCol ].point_y, 30, 30);
        if (GameField->GetCell(defined_ixRow, defined_ixCol) != 0)
        {
            QString y(QString::number(GameField->GetCell(defined_ixRow, defined_ixCol),10));
            painter->drawText(GameField->parameters[ defined_ixRow ][ defined_ixCol ].p_x, GameField->parameters[ defined_ixRow ][ defined_ixCol ].p_y, y);
        }
    }
}
//Изменение раскраски поля по массиву чисел
void MainWindow::paintEvent(QPaintEvent *)
{
    int pointIxRow = 10;
    int pointIxCol = 50;
    int p1 = 18;
    int p2 = 75;
    QPen pen;
    pen.setWidth(3);
    DrawPole(pen, pointIxRow, pointIxCol);
    pointIxRow = 10;
    pointIxCol = 50;
    if (is_New_Game_Activated == true)
    {
        DrawCells();
        DrawText(p1, p2);
    }
    p1 = 18;
    p2 = 75;
    pointIxRow = 10;
    pointIxCol = 50;
    DrawEvent();
    this->resize(360, 350);
    painter->end();
}
MainWindow::~MainWindow()
{
    delete ui;
    delete[] easy;
    delete[] normal;
    delete[] hard;
    delete[] lay;
}
//Выбор уровня
void MainWindow::ChoiceLevel()
{
    leveldialog = new QDialog;
    easy = new QPushButton("&Easy");
    normal = new QPushButton("&Normal");
    hard = new QPushButton("&Hard");
    connect(easy, SIGNAL(clicked()),SLOT(firstlevel()));
    connect(normal, SIGNAL(clicked()),SLOT(secondlevel()));
    connect(hard, SIGNAL(clicked()),SLOT(thirdlevel()));
    lay = new QGridLayout;
    lay->addWidget(easy, 0, 0);
    lay->addWidget(normal, 1, 0);
    lay->addWidget(hard, 2, 0);
    leveldialog->setLayout(lay);
    leveldialog->show();
}
//Начало новой игры
void MainWindow::CreateNewGame(int choice)
{
    GameField = new Field;
    Save_Graphic_Options();
    save_game = new SavedGames;
    GameField->Fill_Zero(choice);
    GameField->CreateGraphicField();
    save_game->SaveReadyField(GameField, "CurrentGameField.txt");
    is_New_Game_Activated = true;
    is_Load_Game_Activated = false;
    is_Mouse_Clicked = false;
    is_Checking = false;
    if (is_New_Game_Activated == true)
        repaint();
}
//Легкий уровень
void MainWindow::firstlevel()
{
    int choice = 4;
    CreateNewGame(choice);
    leveldialog->close();
}
//Средний уровень
void MainWindow::secondlevel()
{
    int choice = 5;
    CreateNewGame(choice);
    leveldialog->close();
}
//Трудный уровень
void MainWindow::thirdlevel()
{
    int choice = 6;
    CreateNewGame(choice);
    leveldialog->close();
}
//Обработка событий мыши
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    is_Keyboard_activated = false;
    if (is_New_Game_Activated == true)
    {
        if (ev->button() == Qt::LeftButton)
        {
            is_Mouse_Clicked = true;
            is_New_Game_Activated = true;
            if (is_Mouse_Clicked == true)
            {
                QPoint p = ev->pos();
                if ((p.y() >= 50) && (p.y() <= 350) && (p.x() >= 10) && (p.x() <= 310))
                {
                    int ixRow = (p.y()-50)/30;
                    int ixCol = (p.x()-10)/30;
                    if (GameField->GraphicField[ ixRow ][ ixCol ] == 0)
                    {
                        defined_ixRow = ixRow;
                        defined_ixCol = ixCol;
                        is_Keyboard_activated = true;
                        repaint();
                    }
                }
            }
        }
    }
}
//Диалог сохранения игры
void MainWindow::SaveDialog()
{
    savedialog = new QDialog;
    save = new QPushButton("&Save");
    cancel = new QPushButton("&Cancel");
    savelay = new QGridLayout;
    connect(save,SIGNAL(clicked()),SLOT(save_pressed()));
    connect(cancel,SIGNAL(clicked()),SLOT(cancel_press()));
    savelay->addWidget(save, 0, 0);
    savelay->addWidget(cancel, 0, 1);
    savedialog->setLayout(savelay);
    savedialog->show();
}
void MainWindow::save_pressed()
{
    save_game->SaveRequest(GameField);
    savedialog->close();
}
void MainWindow::cancel_press()
{
    savedialog->close();
}
//Загрузка игры
void MainWindow::LoadGame()
{
    GameField = new Field;
    GameField->CreateGraphicField();
    Save_Graphic_Options();
    save_game = new SavedGames;
    save_game->LoadRequest(GameField);
    is_Load_Game_Activated = false;
    is_New_Game_Activated = true;
    is_Mouse_Clicked = false;
    is_Checking = false;
    if (is_New_Game_Activated == true)
        repaint();
}
//Проверка поля
void MainWindow::Checking()
{
    is_Checking = true;
    is_Mouse_Clicked = false;
    is_New_Game_Activated = true;
    tips = 0;
    if (is_Checking == true)
        repaint();
}
//Сохранение графичеких опций
void MainWindow::Save_Graphic_Options()
{
    int pointIxRow = 10;
    int pointIxCol = 50;
    int p1 = 18;
    int p2 = 75;
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            GameField->Graphic_Parameters(ixRow, ixCol, pointIxRow, pointIxCol, p1, p2);
            p1 = p1+30;
            pointIxRow = pointIxRow+30;
        }
        p1 = 18;
        pointIxRow = 10;
        pointIxCol = pointIxCol+30;
        p2 = p2+30;
    }
}
//Включение подсказок
void MainWindow::Include_Tips()
{
    tips = 1;
    is_Checking = false;
}
//Выключение подсказок
void MainWindow::Switch_off_Tips()
{
    tips = 0;
    is_Checking = false;
}
//Рисование подсказок
void MainWindow::PaintTips(int &ixRow, int& ixCol)
{
    painter->setBrush(QBrush(Qt::yellow, Qt::Dense1Pattern));
    if (GameField->SearchRepeatsRow(ixRow, ixCol) == 1)
    {
        painter->drawRect(GameField->parameters[ GameField->x ][ GameField->y ].point_x, GameField->parameters[ GameField->x ][ GameField->y ].point_y, 30, 30);
        QString y(QString::number(GameField->GameField[ GameField->x ][ GameField->y ], 10));
        painter->drawText(GameField->parameters[ GameField->x ][ GameField->y ].p_x, GameField->parameters[ GameField->x ][ GameField->y ].p_y, y);
    }
    if (GameField->SearchRepeatsCol(ixRow, ixCol) == 1)
    {
        painter->drawRect(GameField->parameters[ GameField->x ][ GameField->y ].point_x, GameField->parameters[ GameField->x ][ GameField->y ].point_y, 30, 30);
        QString y(QString::number(GameField->GameField[ GameField->x ][ GameField->y ], 10));
        painter->drawText(GameField->parameters[ GameField->x ][ GameField->y ].p_x, GameField->parameters[ GameField->x ][ GameField->y ].p_y, y);
    }
    GameField->SearchRepeatsSq(ixRow, ixCol);
    for (int i = 0; i < 9; i++)
    {
        if (GameField->mass_x[ i ] != 10)
        {
            painter->drawRect(GameField->parameters[ GameField->mass_x[ i ] ][ GameField->mass_y[ i ] ].point_x, GameField->parameters[ GameField->mass_x[ i ] ][ GameField->mass_y[ i ] ].point_y, 30, 30);
            QString y(QString::number(GameField->GameField[ GameField->mass_x[ i ] ][ GameField->mass_y[ i ] ], 10));
            painter->drawText(GameField->parameters[ GameField->mass_x[ i ] ][ GameField->mass_y[ i ] ].p_x, GameField->parameters[ GameField->mass_x[ i ] ][ GameField->mass_y[ i ] ].p_y, y);
        }
    }
    painter->setBrush(QBrush(Qt::red, Qt::Dense1Pattern));
    painter->drawRect(GameField->parameters[ ixRow ][ ixCol ].point_x, GameField->parameters[ ixRow ][ ixCol ].point_y, 30, 30);
}
//Закрашивание клеток с ошибками
void MainWindow::Paint_Mistakes()
{
    for (int ixRow = 0; ixRow < 9; ixRow++)
    {
        for (int ixCol = 0; ixCol < 9; ixCol++)
        {
            if (GameField->GameField[ ixRow ][ ixCol ] != GameField->FieldVictory[ ixRow ][ ixCol ])
            {
                painter->setBrush(QBrush(Qt::red, Qt::Dense1Pattern));
                painter->drawRect(GameField->parameters[ ixRow ][ ixCol ].point_x, GameField->parameters[ ixRow ][ ixCol ].point_y, 30, 30);
            }
        }
    }
}
//Проверка игрока на победу
void MainWindow::Define_Victory()
{
    if (GameField->Define_Victory() == true)
    {
        is_New_Game_Activated = false;
        WinDialog* Win = new WinDialog;
        Win->show();
        repaint();
    }
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//События нажатия клавиш
void MainWindow::on_pushButton_clicked()
{
    int chislo = 1;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    int chislo = 2;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    int chislo = 3;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    int chislo = 4;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_5_clicked()
{
    int chislo = 5;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    int chislo = 6;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_7_clicked()
{
    int chislo = 7;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_8_clicked()
{
    int chislo = 8;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
void MainWindow::on_pushButton_9_clicked()
{
    int chislo = 9;
    if (is_Keyboard_activated == true)
    {
        GameField->InsertChislo(defined_ixRow, defined_ixCol, chislo);\
        repaint();
        Define_Victory();
    }
}
