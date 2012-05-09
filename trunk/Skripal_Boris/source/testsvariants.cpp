#include "testsvariants.h"
#include "ui_testsvariants.h"

testsVariants::testsVariants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testsVariants)
{
    ui->setupUi(this);
}

testsVariants::~testsVariants()
{
    delete ui;
}

void testsVariants::on_buttonBox_accepted()
{
    if(ui->radioButton->isChecked())
        typeOfTest = 1;
    if(ui->radioButton_2->isChecked())
        typeOfTest = 2;
    if(ui->radioButton_3->isChecked())
        typeOfTest = 3;
    if(ui->radioButton_4->isChecked())
        typeOfTest = 4;
}

int testsVariants::getTypeOfTest()
{
    return typeOfTest;
}
