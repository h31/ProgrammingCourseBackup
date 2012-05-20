#include <Field.h>

#include <peremenny.h>
void MyLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

   // GameField* field;
  //  field = new GameField;
 //   int ocherednost;
    //ocherednost++;
 //   QMessageBox::warning(this, QString("Info"), QString(ocherednost + '0'));
    QPen PenBlack;
    PenBlack.setColor(Qt::black);
    PenBlack.setWidth(5);
    setPen(PenBlack);
    isChecked = true;

    Phonon::MediaObject* object = Phonon::createPlayer(Phonon::MusicCategory,
    Phonon::MediaSource("phone-hang-up-1.mp3"));
        object->play();

    //emit mySignal();

///////////////////////////////////
/*
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
*/
/////////////////////////////////////
    //
          //tu=new TurnText(str2);

    //    else
        //    tu=new TurnText(str1);


}

void MyText::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QFont cross("Arial", 25, QFont::Bold);
    setPlainText("x");
    setFont(cross);
    setDefaultTextColor(Qt::red);

}

void MyText::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * event )
{
    QFont circle("Arial", 25, QFont::Bold);
    setPlainText("o");
    setFont(circle);
    setDefaultTextColor(Qt::blue);
}


