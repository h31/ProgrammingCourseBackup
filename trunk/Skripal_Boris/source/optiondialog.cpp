#include "optiondialog.h"
#include "ui_optiondialog.h"
optionDialog::optionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionDialog)
{
    ui->setupUi(this);
    std::ifstream sett("setting.txt");
    int hours,minutes,seconds,blink;
    sett>>hours>>minutes>>seconds>>blink;
    ui->horizontalSlider->setValue(hours);
    ui->spinBox->setValue(hours);
    ui->horizontalSlider_2->setValue(minutes);
    ui->spinBox_2->setValue(minutes);
    ui->horizontalSlider_3->setValue(seconds);
    ui->spinBox_3->setValue(seconds);
    ui->horizontalSlider_4->setValue(blink);
    ui->spinBox_4->setValue(blink);
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),ui->spinBox,SLOT(setValue(int)));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
    connect(ui->horizontalSlider_2,SIGNAL(sliderMoved(int)),ui->spinBox_2,SLOT(setValue(int)));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),ui->horizontalSlider_2,SLOT(setValue(int)));
    connect(ui->horizontalSlider_3,SIGNAL(sliderMoved(int)),ui->spinBox_3,SLOT(setValue(int)));
    connect(ui->spinBox_3,SIGNAL(valueChanged(int)),ui->horizontalSlider_3,SLOT(setValue(int)));
    connect(ui->horizontalSlider_4,SIGNAL(sliderMoved(int)),ui->spinBox_4,SLOT(setValue(int)));
    connect(ui->spinBox_4,SIGNAL(valueChanged(int)),ui->horizontalSlider_4,SLOT(setValue(int)));
    sett.close();
}

optionDialog::~optionDialog()
{
    delete ui;
}

void optionDialog::on_buttonBox_accepted()
{
    std::ofstream sett("setting.txt");
    sett<<ui->horizontalSlider->value()<<" "<<ui->horizontalSlider_2->value()<<" "<<ui->horizontalSlider_3->value()<<" "<<ui->horizontalSlider_4->value();
    sett.close();
    changesAccepted();
}

void optionDialog::on_pushButton_clicked()
{
    std::ofstream sett("setting.txt");
    sett<<0<<" "<<45<<" "<<0<<" "<<250;
    sett.close();
    changesAccepted();
    this->close();
}
