#include "mainwindow.h"
#include "savedgames.h"
#include "game.h"
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QtGui>

MainWindow::MainWindow()
{
    CreateActions();
    CreateMenu();
}

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
}


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
    Game->addAction(exitAction);
    this->setMenuBar(bar);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int pointIxRow = 10;
    int pointIxCol = 50;
    QPen pen;
    pen.setWidth(3);


    QPainter* painter = new QPainter;
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
            painter->drawRect(pointIxRow, pointIxCol, 30, 30);
            pointIxRow = pointIxRow+30;
        }
        pointIxRow = 10;
        pointIxCol = pointIxCol+30;
    }
    int p1 = 18;
    int p2 = 75;
    if (is_New_Game_Activated == true)
    {
        painter->setFont(QFont("Times", 20, QFont::Normal));
        for (int ixRow = 0 ; ixRow < 9; ixRow++)
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
    p1 = 18;
    p2 = 75;
    if (is_Load_Game_Activated == true)
    {
        painter->setFont(QFont("Times", 20, QFont::Normal));
        for (int ixRow = 0 ; ixRow < 9; ixRow++)
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
    pointIxRow = 10;
    pointIxCol = 50;
    p1 = 18;
    p2 = 75;
    if (is_Checking == true)
    {
        int count = 0;
        for (int ixRow = 0 ; ixRow < 9; ixRow++)
        {
            for (int ixCol = 0; ixCol < 9; ixCol++)
            {
                if (GameField->GameField[ ixRow ][ ixCol ] != GameField->FieldVictory[ ixRow ][ ixCol ])
                {
                    painter->setBrush(QBrush(Qt::red, Qt::Dense4Pattern));
                    painter->drawRect(pointIxRow, pointIxCol, 30, 30);
                    pointIxRow = pointIxRow+30;
                    count++;
                }
                if (GameField->GameField[ ixRow ][ ixCol ] == GameField->FieldVictory[ ixRow ][ ixCol ])
                {
                    painter->setBrush(QBrush(Qt::green, Qt::Dense4Pattern));
                    painter->drawRect(pointIxRow, pointIxCol, 30, 30);
                    pointIxRow = pointIxRow+30;
                }
            }
            pointIxRow = 10;
            pointIxCol = pointIxCol+30;
        }
        painter->setFont(QFont("Times", 20, QFont::Normal));
        for (int ixRow = 0 ; ixRow < 9; ixRow++)
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
        if (count == 0)
        {
            QMessageBox::information(this, "You win!", "You win!");
        }
    }
    if (is_Mouse_Clicked == true)
    {
        QString y(QString::number(GameField->GetCell(defined_ixRow, defined_ixCol),10));
        painter->drawText(GameField->parameters[ defined_ixRow ][ defined_ixCol ].p_x, GameField->parameters[ defined_ixRow ][ defined_ixCol ].p_y, y);
    }
    this->resize(300, 350);
    painter->end();
}

MainWindow::~MainWindow()
{
    delete[] easy;
    delete[] normal;
    delete[] hard;
    delete[] lay;
}

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

void MainWindow::CreateNewGame(int choice)
{
    GameField = new Field;
    Save_Graphic_Options();
    save_game = new SavedGames;
    GameField->Fill_Zero(choice);
    save_game->SaveReadyField(GameField, "CurrentGameField.txt");
    is_New_Game_Activated = true;
    is_Load_Game_Activated = false;
    is_Mouse_Clicked = false;
    is_Checking = false;
    if (is_New_Game_Activated == true)
        repaint();
}

void MainWindow::firstlevel()
{
    int choice = 4;
    CreateNewGame(choice);
    leveldialog->close();
}

void MainWindow::secondlevel()
{
    int choice = 5;
    CreateNewGame(choice);
    leveldialog->close();
}

void MainWindow::thirdlevel()
{
    int choice = 6;
    CreateNewGame(choice);
    leveldialog->close();
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::RightButton)
    {
        is_Mouse_Clicked = true;
        is_Load_Game_Activated = false;
        is_New_Game_Activated = true;
        is_Checking = false;
        if (is_Mouse_Clicked == true)
        {
            QPoint p = ev->pos();
            int ixRow = (p.y()-50)/30;
            int ixCol = (p.x()-10)/30;
            defined_ixRow = ixRow;
            defined_ixCol = ixCol;

            int test = QInputDialog::getInt(this, "Enter number", "number: ", 0, 1, 9, 1);

            GameField->InsertChislo(ixRow, ixCol, test);
            repaint();
        }
    }
}


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

void MainWindow::LoadGame()
{
    GameField = new Field;
    Save_Graphic_Options();
    save_game = new SavedGames;
    save_game->LoadRequest(GameField);
    is_Load_Game_Activated = true;
    is_New_Game_Activated = false;
    is_Mouse_Clicked = false;
    is_Checking = false;
    if (is_Load_Game_Activated == true)
        repaint();
}

void MainWindow::Checking()
{
    is_Checking = true;
    is_Load_Game_Activated = false;
    is_Mouse_Clicked = false;
    is_New_Game_Activated = false;
    if (is_Checking == true)
        repaint();
}

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






































