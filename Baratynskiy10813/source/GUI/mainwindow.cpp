#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "russianwidget.h"
#include "mainwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window,
    QBrush(QPixmap("C://Hangman/screen1.png")));
    this->setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    RussianWidget *widget = new RussianWidget;
    widget->play();
    widget->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    MainWidget *widget = new MainWidget;
    widget->play();
    widget->show();
}
