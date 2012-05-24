#include <Field.h>
#include <Game.h>
#include <peremenny.h>



void GameFieldA::InitializationField()
{
    VerticalLine.resize(w+1);
    HorizontalLine.resize(w+1);
    for(int i = 0; i < w+1; i++)
    {
        VerticalLine[i].resize(w+1);
        HorizontalLine[i].resize(w+1);
        for(int j = 0; j < h; j++)
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
    CellText.resize(w+1);
    for(int i = 0; i < w; i++)
        {
        CellText[i].resize(w+1);
            for(int j = 0; j < h; j++)
            {
                CellText[i][j]=new MyText("~~");
                CellText[i][j]->setPos(200 + i*40, 200 + j*40);

                GameScene->addItem(CellText[i][j]);

            }
    }

    finished=new QGraphicsTextItem("Click for winner name!");
    finished->setPos(350,150);
    GameScene->addItem(finished);


    hello = new QGraphicsTextItem("Now Is Turn:");
    hello->setPos(320, 120);
    tu=new TurnText(string1);

    tu->setPos(420, 120);
    tu->setDefaultTextColor(Qt::red);
    GameScene->addItem(hello);
    GameScene->addItem(tu);


    for(int i = 0; i < w; i++)
        {
        for(int j = 0; j < w; j++)
            {
       //     QObject* line = (QObject*)VerticalLine[i][j];
            connect(VerticalLine[i][j], SIGNAL(mySignal()),
                            this, SLOT(mySlot()));
            }
    }

    for(int i = 0; i < w; i++)
        {
        for(int j = 0; j < w; j++)
            {
        //  QObject* line1 = (QObject*)HorizontalLine[i][j];
            connect(HorizontalLine[i][j], SIGNAL(mySignal()),
                            this, SLOT(mySlot()));

            }
        }
  //  connect(finished, SIGNAL(winSignal()),
   //                 this, SLOT(winSlot()));

}

/*

void GameFieldQ::InitializationField()
{
    VerticalLine.resize(a+1);
    HorizontalLine.resize(a+1);
    for(int i = 0; i < a+1; i++)
    {
        VerticalLine[i].resize(a+1);
        HorizontalLine[i].resize(a+1);
        for(int j = 0; j < a; j++)
        {
            VerticalLine[i][j]=new MyLine(200+40*i,200+40*j,200+40*i,240+40*j);
            VerticalLine[i][j]->isChecked = false;
            HorizontalLine[i][j]=new MyLine(200+40*j,200+40*i,240+40*j,200+40*i);
            HorizontalLine[i][j]->isChecked = false;
            VerticalLine[i][j]->setPen(PenGray);
            HorizontalLine[i][j]->setPen(PenGray);
       //     VerticalLine[i][j]->ocherednost=0;
       //     HorizontalLine[i][j]->ocherednost=0;
            GameScene->addItem(VerticalLine[i][j]);
            GameScene->addItem(HorizontalLine[i][j]);
        }
    }
    CellText.resize(a+1);
    for(int i = 0; i < a; i++)
        {
        CellText[i].resize(a+1);
            for(int j = 0; j < a; j++)
            {
                CellText[i][j]=new MyText("~~");
                CellText[i][j]->setPos(200 + i*40, 200 + j*40);

                GameScene->addItem(CellText[i][j]);

            }
    }
*/
/*
    for(int i = 0; i < a; i++)
        {
        for(int j = 0; j < a; j++)
            {
            connect(VerticalLine[i][j], SIGNAL(mySignal()),
                            this, SLOT(mySlot()));
            }
    }

    for(int i = 0; i < a; i++)
        {
        for(int j = 0; j < a; j++)
            {
            connect(HorizontalLine[i][j], SIGNAL(mySignal()),
                            this, SLOT(mySlot()));
            }
    }

    */
/*
    finished=new QGraphicsTextItem("Click for winner name!");
    finished->setPos(350,150);
    GameScene->addItem(finished);


    hello = new QGraphicsTextItem("Now Is Turn:");
    hello->setPos(320, 120);
    tu=new TurnText(string1);

    tu->setPos(420, 120);
    tu->setDefaultTextColor(Qt::red);
    GameScene->addItem(hello);
    GameScene->addItem(tu);

   // connect(VerticalLine[0][0], SIGNAL(mySignal()),
      //              this, SLOT(mySlot()));

}
*/
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


MyLine::MyLine(int x1, int x2, int x3, int x4) : QGraphicsLineItem(x1,x2,x3,x4)
{

}
MyText::MyText(const QString q) : QGraphicsTextItem(q) {}
//WinText::WinText(const QString q) : QGraphicsTextItem(q) {}
TurnText::TurnText(const QString q) : QGraphicsTextItem(q) {}




Game::Game()
{

}

int GameFieldA::CheckField()
{
    int red = 0;
    int blue = 0;

    for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(CellText[i][j]->toPlainText() == "x")
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

void GameFieldA::InitializationField()
{
    VerticalLine.resize(a+1);
    HorizontalLine.resize(a+1);
    for(int i = 0; i < a+1; i++)
    {
        VerticalLine[i].resize(a+1);
        HorizontalLine[i].resize(a+1);
        for(int j = 0; j < a; j++)
        {
            VerticalLine[i][j]=new MyLine(200+40*i,200+40*j,200+40*i,240+40*j);
            VerticalLine[i][j]->isChecked = false;
            HorizontalLine[i][j]=new MyLine(200+40*j,200+40*i,240+40*j,200+40*i);
            HorizontalLine[i][j]->isChecked = false;
            VerticalLine[i][j]->setPen(PenGray);
            HorizontalLine[i][j]->setPen(PenGray);
       //     VerticalLine[i][j]->ocherednost=0;
       //     HorizontalLine[i][j]->ocherednost=0;
            GameScene->addItem(VerticalLine[i][j]);
            GameScene->addItem(HorizontalLine[i][j]);
        }
    }
    CellText.resize(a+1);
    for(int i = 0; i < a; i++)
        {
        CellText[i].resize(a+1);
            for(int j = 0; j < a; j++)
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

