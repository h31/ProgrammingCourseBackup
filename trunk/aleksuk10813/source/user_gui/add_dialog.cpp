#include "add_dialog.h"
#include "ui_add_dialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_buttonBox_accepted()
{
    address = ui->address->text();
    protocol = ui->protocol->text();
    accepted = true;
}

void AddDialog::on_buttonBox_rejected()
{
    accepted = false;
}
