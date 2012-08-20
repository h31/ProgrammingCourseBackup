#include "ifwinwidget.h"
#include "ui_ifwinwidget.h"
#include "mainwidget.h"

IfWinWidget::IfWinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IfWinWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->yes,SIGNAL(clicked()),this,SLOT(close()));
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
    QPainter qp;
    QPixmap pix;
    pix.load("C://Hangman/troll.png");
    qp.drawPixmap(0,0,pix);
    ui->label_3->setPixmap(pix);
}

IfWinWidget::~IfWinWidget()
{
    delete ui;
}

void IfWinWidget::on_yes_clicked()
{
    MainWidget *widget = new MainWidget;
    widget->play();
}
QPushButton* IfWinWidget::returnYes()
{
    return ui->yes;
}
QPushButton* IfWinWidget::returnNo()
{
    return ui->no;
}
