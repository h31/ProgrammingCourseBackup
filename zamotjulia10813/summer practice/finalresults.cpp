#include "finalresults.h"

FinalResults::FinalResults(int newscore,QWidget *parent):QDialog(parent)
{
    setMinimumSize(640, 480);
    setMaximumSize(640, 480);
    resize(640, 480);
    this->score=newscore;
    Editname = new QLineEdit("N1",this);
    ButtonCommit = new QPushButton("OK",this);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(Editname);
    layout->addWidget(ButtonCommit);

    connect(this->ButtonCommit,SIGNAL(clicked()),SLOT(oncommitname()));

    this->setLayout(layout);
}

void FinalResults::oncommitname()
{
    SaveToFile();
    this->close();
}
bool FinalResults::SaveToFile()
{
    QFile file("ScoresList.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return false;
    QTextStream out(&file);
            out << Editname->text();
            out<<"\t";
            out<<score;
            out << "\n";
    file.close();
            return true;
}
void FinalResults::paintEvent(QPaintEvent *)
{
}
