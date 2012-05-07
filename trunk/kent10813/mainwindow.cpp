#include "mainwindow.h"
#include "Game.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    im.load("C:/QtProjects/BJ/images/green.jpg");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    pen.begin(this);
    pen.drawImage(0, 0, im.scaled(width(), height() ) );
    pen.end();
}

