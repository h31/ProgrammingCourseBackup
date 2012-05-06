#include "chanchepawn.h"
#include "ui_chanchepawn.h"

ChanchePawn::ChanchePawn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChanchePawn)
{
    ui->setupUi(this);
}

ChanchePawn::~ChanchePawn()
{
    delete ui;
}


int ChanchePawn::getTypeOfFigure()
{
    return typeOfFigure;
}

void ChanchePawn::on_buttonBox_accepted()
{
    if(ui->radioButton->isChecked())
         typeOfFigure = 2;
    if(ui->radioButton_2->isChecked())
         typeOfFigure = 1;
    if(ui->radioButton_3->isChecked())
         typeOfFigure = 3;
    if(ui->radioButton_4->isChecked())
         typeOfFigure = 4;
}
