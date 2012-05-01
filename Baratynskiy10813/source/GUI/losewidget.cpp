#include "losewidget.h"
#include "widget.h"

LoseWidget::LoseWidget(QWidget *parent) :
    QWidget(parent)
{
    label1 = new QLabel("You lose!");
    label2 = new QLabel("Do you want to play again?");
    QFont font1 = label1->font();
    font1.setPointSize(20);
    label1->setFont(font1);
    QFont font = label2->font();
    font.setPointSize(20);
    label2->setFont(font);
    yes = new QPushButton("Yes");
    no = new QPushButton("No");
    layout = new QGridLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(yes);
    layout->addWidget(no);
    setLayout(layout);
    QObject::connect(yes,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(no,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(yes,SIGNAL(clicked()),this,SLOT(on_yes_clicked()));
}

void LoseWidget::on_yes_clicked()
{
    Widget *widget = new Widget;
    widget->play();
}
