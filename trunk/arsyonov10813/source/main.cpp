#include <Field.h>
#include <peremenny.h>
#include "mainwindow.h"
#include <QWaitCondition>


//   QString str1;
//   QString str2;

//   TurnText* tu;



int main(int argc, char *argv[])
{
    int h = 10;
    int wi = 15;
    //ocherednost = 0;
    QApplication a(argc, argv);

    MainWindow w;

    QString str1;
    QString str2;



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




    QHBoxLayout* fieldlayout = new QHBoxLayout;
    w.setLayout(fieldlayout);

  //  GameField* field;
 //   w.field = field;
    GameFieldQ *field;

    field = new GameFieldQ(h, wi, str1, str2);


    field->GameScene = new QGraphicsScene;


    QGraphicsView* fieldwiew = new QGraphicsView(field->GameScene);

    fieldlayout->addWidget(fieldwiew);

    field->InitializationField();

    fieldwiew->show();

 //   w.show();

    //////////////////////////////////////////

    QHBoxLayout* gamelayout = new QHBoxLayout;
    w.setLayout(gamelayout);


 //   Game* GAME = new Game;


//    MainScene = new QGraphicsScene;


 //   QGraphicsView* gamewiew = new QGraphicsView(GAME->MainScene);

//    gamelayout->addWidget(gamewiew);

 //   GAME->PreparingGame();

   // gamewiew->show();

//    QString str1;
//    QString str2;

//    TurnText* tu;

 //   QGraphicsScene* MainScene;
 //   MainScene = new QGraphicsScene;


 //   QGraphicsView* gamewiew = new QGraphicsView(MainScene);

 //   gamelayout->addWidget(gamewiew);



 //   gamewiew->show();

 //   QString str1;
   // QString str2;

 //   QString str1;
 //   QString str2;
  //  TurnText* tu;





/*
    QGraphicsTextItem* hello = new QGraphicsTextItem("Now Is Turn:");
    hello->setPos(100, 100);
    tu=new TurnText(str1);

    tu->setPos(200, 100);
    tu->setDefaultTextColor(Qt::red);
    MainScene->addItem(hello);
    MainScene->addItem(tu);

    */
////////////////////////////////////


/*
    for(;;)
    {
        int razdvatri = 0;
        for(int i = 0; i < 11; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(field->VerticalLine[i][j]->isChecked == true)

                        razdvatri++;

                    if(field->HorizontalLine[i][j]->isChecked == true)

                        razdvatri++;

                }
            }
        if(razdvatri%2==0)
            tu=new TurnText(str1);
        else
           tu=new TurnText(str2);

    }
*/
////////////////////////////////////



    return a.exec();
}





GameFieldA::GameFieldA(int height, int width,  QString str1, QString str2)
{
    PenGray.setColor(Qt::gray);
    PenGray.setWidth(5);
    h = height;
    w = width;
    string1 = str1;
    string2 = str2;

}

GameFieldA::~GameFieldA()
{
}
/*
GameFieldQ::GameFieldQ(int height, int width, QString str1, QString str2)
{
    PenGray.setColor(Qt::gray);
    PenGray.setWidth(5);
    if(height >= width)
    {
        h = height;
        w = height;
    }
    else
    {
        h = width;
        w = width;
    }
    string1 = str1;
    string2 = str2;


}
*/
