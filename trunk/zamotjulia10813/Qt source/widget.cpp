#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Snake");
    QVBoxLayout* layout = new QVBoxLayout();
    button1 = new QPushButton("Game");
    button2 = new QPushButton("Show score");
    button3 = new QPushButton("Exit");
    button4 = new QPushButton("About");
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    this->setLayout(layout);
    Gdialog = new MyDialog(this);
    Sdialog= new  ScoreDialog(this);
    Abdialog=new AboutDialog(this);

    connect(button1, SIGNAL(clicked()), SLOT(onShowGameDialog()));
    connect(button2, SIGNAL(clicked()), SLOT(onShowScoreDialog()));
    connect(button3, SIGNAL(clicked()), SLOT(close()));
    connect(button4,SIGNAL(clicked()), SLOT(onShowAboutDialog()));
}

Widget::~Widget()
{  
}

void Widget::onShowGameDialog()
{
    Gdialog->show();
}

void Widget::onShowScoreDialog()
{
    Sdialog->show();
}

void Widget::onShowAboutDialog()
{
    Abdialog->show();
}
