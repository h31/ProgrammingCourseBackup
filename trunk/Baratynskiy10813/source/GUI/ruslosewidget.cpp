#include "ruslosewidget.h"
#include "ui_ruslosewidget.h"
#include "russianwidget.h"

RusLoseWidget::RusLoseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RusLoseWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->yes,SIGNAL(clicked()),this,SLOT(close()));
}

RusLoseWidget::~RusLoseWidget()
{
    delete ui;
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
