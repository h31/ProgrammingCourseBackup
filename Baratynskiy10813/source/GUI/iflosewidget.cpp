#include "iflosewidget.h"
#include "ui_iflosewidget.h"
#include "mainwidget.h"
IfLoseWidget::IfLoseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IfLoseWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->yes,SIGNAL(clicked()),this,SLOT(close()));
}

IfLoseWidget::~IfLoseWidget()
{
    delete ui;
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
