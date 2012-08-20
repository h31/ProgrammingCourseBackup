#include "ruswinwidget.h"
#include "ui_ruswinwidget.h"
#include "russianwidget.h"

RusWinWidget::RusWinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RusWinWidget)
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

RusWinWidget::~RusWinWidget()
{
    delete ui;
}

void RusWinWidget::on_yes_clicked()
{
    RussianWidget *widget = new RussianWidget;
    widget->play();
}

QPushButton* RusWinWidget::returnYes()
{
    return ui->yes;
}
QPushButton* RusWinWidget::returnNo()
{
    return ui->no;
}
