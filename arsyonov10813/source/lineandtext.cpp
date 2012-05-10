#include <Field.h>

#include <peremenny.h>
void MyLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QString str1;
    QString str2;
    TurnText* tu;
    GameField* field;
    field = new GameField;


    QPen PenBlack;
    PenBlack.setColor(Qt::black);
    PenBlack.setWidth(5);
    setPen(PenBlack);
    isChecked = true;

    Phonon::MediaObject* object = Phonon::createPlayer(Phonon::MusicCategory,
    Phonon::MediaSource("phone-hang-up-1.mp3"));
        object->play();

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
}

void MyText::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QFont cross("Arial", 25, QFont::Bold);
    setPlainText("X");
    setFont(cross);
    setDefaultTextColor(Qt::red);

}

void MyText::mouseDoubleClickEvent( QGraphicsSceneMouseEvent * event )
{
    QFont circle("Arial", 25, QFont::Bold);
    setPlainText("O");
    setFont(circle);
    setDefaultTextColor(Qt::blue);
}


