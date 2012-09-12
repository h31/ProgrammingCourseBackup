#include "widget.h"

void Widget::paintEvent(QPaintEvent *)
{
    setWindowTitle("Snake");
    QPainter painter(this);
    QLinearGradient gradient (0,0,width(),height());
    gradient.setColorAt(0,Qt::red);
    gradient.setColorAt(0.5,Qt::green);
    gradient.setColorAt(1,Qt::blue);
    painter.setBrush(gradient);
    painter.drawRect(rect());

    QVBoxLayout* layout = new QVBoxLayout();
    button1 = new QPushButton("Game");
    button1->setStyleSheet("background-color: rgb(200, 255, 100);");
    button2 = new QPushButton("Show score");
    button2->setStyleSheet("background-color: rgb(200, 255, 100);");
    button3 = new QPushButton("Exit");
    button3->setStyleSheet("background-color: rgb(200, 255, 100);");
    button4 = new QPushButton("About");
    button4->setStyleSheet("background-color: rgb(200, 255, 100);");

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button4);
    layout->addWidget(button3);

    this->setLayout(layout);
    Gdialog = new MyDialog(this);
    Sdialog= new  ScoreDialog(this);
    Abdialog=new AboutDialog(this);

    connect(button1, SIGNAL(clicked()), SLOT(onShowGameDialog()));
    connect(button2, SIGNAL(clicked()), SLOT(onShowScoreDialog()));
    connect(button3, SIGNAL(clicked()), SLOT(close()));
    connect(button4,SIGNAL(clicked()), SLOT(onShowAboutDialog()));
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPaintEvent *image;
    paintEvent(image);
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
