#include "ruslosewidget.h"
#include "ui_ruslosewidget.h"
#include "russianwidget.h"

RusLoseWidget::RusLoseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RusLoseWidget)
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

RusLoseWidget::~RusLoseWidget()
{
    delete ui;
}

QLabel* RusLoseWidget::getLabel()
{
    return ui->label_3;
}

void RusLoseWidget::on_yes_clicked()
{
    RussianWidget *widget = new RussianWidget;
    widget->play();
}

QPushButton* RusLoseWidget::returnYes()
{
    return ui->yes;
}
QPushButton* RusLoseWidget::returnNo()
{
    return ui->no;
}
