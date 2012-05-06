#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    pen.begin(this);
    im.load("C:/QtProjects/BJ/images/green.jpg");
    pen.drawImage(width(),height(),im);
    pen.end();

}
