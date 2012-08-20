#include "iflosewidget.h"
#include "ui_iflosewidget.h"
#include "mainwidget.h"
IfLoseWidget::IfLoseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IfLoseWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->yes,SIGNAL(clicked()),this,SLOT(close()));
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
    QPainter qp;
    QPixmap pix;
    pix.load("C://Hangman/okay.png");
    qp.drawPixmap(0,0,pix);
    ui->label_4->setPixmap(pix);
}

IfLoseWidget::~IfLoseWidget()
{
    delete ui;
}

QLabel* IfLoseWidget::getLabel()
{
    return ui->label_3;
}

void IfLoseWidget::on_yes_clicked()
{
    MainWidget *widget = new MainWidget;
    widget->play();
}

QPushButton* IfLoseWidget::returnYes()
{
    return ui->yes;
}
QPushButton* IfLoseWidget::returnNo()
{
    return ui->no;
}
