#include "windialog.h"
#include "ui_windialog.h"

WinDialog::WinDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(on_pushButton_clicked()));
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_pushButton_clicked()
{
    this->close();
}
