#include "docastling.h"
#include "ui_docastling.h"

docastling::docastling(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::docastling)
{
    ui->setupUi(this);
}

docastling::~docastling()
{
    delete ui;
}

bool docastling::getDoCastling()
{
    return doCastling;
}

void docastling::on_buttonBox_accepted()
{
    doCastling = true;
}

void docastling::on_buttonBox_rejected()
{
    doCastling = false;
}
