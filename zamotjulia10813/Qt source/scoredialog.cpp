#include "scoredialog.h"
ScoreDialog::ScoreDialog(QWidget *parent) :
    QDialog(parent)
{
    LoadFromFile();
    if(all.size()>0)
    {
        QString full;
        for(unsigned int i=0;i<all.size();i++)
        {
            full+=all[i]+"\n";
        }
        text =new QLabel(full,this);
        text->show();
    }

}

ScoreDialog::~ScoreDialog()
{

}

void ScoreDialog::paintEvent(QPaintEvent *)
{
    QPainter qp;
    qp.begin(this);

    //qp.setPen(QPen(Qt::red, 3, Qt::DashLine));
    //qp.drawRect(QRect(100, 100, 100, 100));
    qp.end();
}


bool ScoreDialog::LoadFromFile()
{

    QFile file("ScoresList.txt");
    //file.open(QIODevice::ReadWrite);
    if (!file.open(QIODevice::ReadOnly ))
        return false;
    QTextStream in(&file);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        all.push_back(line);
    }
    file.close();
    return true;
}
