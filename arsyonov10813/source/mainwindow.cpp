#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Field.h>

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Return:
        {


        if(field->CheckField() == 1)
        field->finished=new QGraphicsTextItem("Red player win!");
        if(field->CheckField() == 2)
        field->finished=new QGraphicsTextItem("Blue player win!");
        if(field->CheckField() == 3)
        field->finished=new QGraphicsTextItem("Won the friendship!");
        }
        break;
     //   case Qt::Key_Space:
    //    lineEdit->setText("Space Pressed");
    //    break;
    //    default:
     //   QWidget::keyPressEvent(event);
    }
}
