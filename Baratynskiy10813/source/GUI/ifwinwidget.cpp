#include "ifwinwidget.h"
#include "ui_ifwinwidget.h"
#include "mainwidget.h"

IfWinWidget::IfWinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IfWinWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->yes,SIGNAL(clicked()),this,SLOT(close()));
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
