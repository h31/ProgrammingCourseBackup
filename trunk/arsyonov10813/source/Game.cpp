#include <Field.h>
#include <Game.h>
#include <peremenny.h>



void GameField::InitializationField()
{
    VerticalLine.resize(11);
    HorizontalLine.resize(11);
    for(int i = 0; i < 11; i++)
    {
        VerticalLine[i].resize(11);
        HorizontalLine[i].resize(11);
        for(int j = 0; j < 10; j++)
        {
            VerticalLine[i][j]=new MyLine(200+40*i,200+40*j,200+40*i,240+40*j);
            VerticalLine[i][j]->isChecked = false;
            HorizontalLine[i][j]=new MyLine(200+40*j,200+40*i,240+40*j,200+40*i);
            HorizontalLine[i][j]->isChecked = false;
            VerticalLine[i][j]->setPen(PenGray);
            HorizontalLine[i][j]->setPen(PenGray);
            GameScene->addItem(VerticalLine[i][j]);
            GameScene->addItem(HorizontalLine[i][j]);
        }
    }
    CellText.resize(11);
    for(int i = 0; i < 10; i++)
        {
        CellText[i].resize(11);
            for(int j = 0; j < 10; j++)
            {
                CellText[i][j]=new MyText("~~");
                CellText[i][j]->setPos(200 + i*40, 200 + j*40);

                GameScene->addItem(CellText[i][j]);

            }
    }
    finished=new QGraphicsTextItem("Click for winner name!");
    finished->setPos(350,150);
    GameScene->addItem(finished);
}
/*
bool GameField::CheckField()
{
    int firstplayer;
    int secondplayer;

    for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {



            }
    }
}
*/
MyLine::MyLine(int x1, int x2, int x3, int x4) : QGraphicsLineItem(x1,x2,x3,x4) {}
MyText::MyText(const QString q) : QGraphicsTextItem(q) {}
TurnText::TurnText(const QString q) : QGraphicsTextItem(q) {}




Game::Game()
{

}

int GameField::CheckField()
{
    int red = 0;
    int blue = 0;

    for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(CellText[i][j]->toPlainText() == "X")
                    red++;
                else
                    blue++;
            }
        }
    if(red > blue)
        return 1;
    if(red < blue)
        return 2;
    if(red == blue)
        return 3;
}

/*
void GameField::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_F9:
        {


        if(CheckField() == 1)
        finished=new QGraphicsTextItem("Red player win!");
        if(CheckField() == 2)
        finished=new QGraphicsTextItem("Blue player win!");
        if(CheckField() == 3)
        finished=new QGraphicsTextItem("Won the friendship!");
        }
        break;
     //   case Qt::Key_Space:
    //    lineEdit->setText("Space Pressed");
    //    break;
    //    default:
     //   QWidget::keyPressEvent(event);
    }
}
/*

void Game::PreparingGame()
{
    bool Ok1;
    str1 = QInputDialog::getText( 0,
                                         "Input the first player name",
                                         "Name:",
                                         QLineEdit::Normal,
                                         "Red player"

                                        );
    if (!Ok1) {
        // Была нажата кнопка Cancel
    }

    bool Ok2;
    str2 = QInputDialog::getText( 0,
                                         "Input the second player name",
                                         "Name:",
                                         QLineEdit::Normal,
                                         "Blue player"

                                        );
    if (!Ok2) {
        // Была нажата кнопка Cancel
    }




    QGraphicsTextItem* hello = new QGraphicsTextItem("Now Is Turn:");
    hello->setPos(100, 100);
    tu=new TurnText(str1);

    tu->setPos(200, 100);
    tu->setDefaultTextColor(Qt::red);
    MainScene->addItem(hello);
    MainScene->addItem(tu);

}
*/

