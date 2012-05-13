#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
{
    setMinimumSize(640, 480);
    setMaximumSize(640, 480);
    resize(640, 480);
    newGame = new Game();
    state1=false;
    state2=false;
}

MyDialog::~MyDialog()
{
}


void MyDialog::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
        //LEFT
        case 16777234:
           this->newGame->Gzmeika->rotateAClockwise();
            break;
        //RIGHT
        case 16777236:
            this->newGame->Gzmeika->rotateClockwise();
            break;
    }
}

void MyDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage imageBack(":/back");
    QImage imageHead(":/head");
    QImage imageBody(":/body");
    QImage imageFood(":/food");
    QImage imageFood2(":/food2");

    //this->setWindowTitle(newGame->Gzmeika->)
    if(!state1 && !state2)
    {
    newGame->Gzmeika->move();
    newGame->updatefield();
    newGame->Gzmeika->checkEatFruct(newGame->Gfructs,newGame->Gfield);

   state1= newGame->Gzmeika->checkSelfEating();
   state2=newGame->Gzmeika->checkWall(newGame->Gfield);

    int Capt;
    for (int x = 0; x < newGame->Gfield->get_height(); x++)

    {
        for (int y = 0; y < newGame->Gfield->get_width(); y++)
        {
            Capt=newGame->Gfield->get_field(x,y);
            switch(Capt)
            {
            case app:
                painter.drawImage(y*16,x*16,imageFood);
                break;
            case pear:
                painter.drawImage(y*16,x*16,imageFood2);
                break;
            case snakehead:
                painter.drawImage(y*16,x*16,imageHead);
                break;
            case snaketail:
                painter.drawImage(y*16,x*16,imageBody);
                break;
            case empty:
                painter.drawImage(y*16,x*16,imageBack);
                break;
            default:
                painter.drawImage(y*16,x*16,imageBack);
                break;



            }
        }

    }
    //this->updateGeometry();
    this->update();
    _sleep(200);
    }

else
{
FinalResults * FN=new FinalResults(newGame->Gzmeika->score,this);
FN->show();
this->close();
}

    }



