#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include<QtGui/QImage>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPainter painter();
    QImage img ("Green.png");
    painter.drawImage(50,50,img);
    w.show();

    
    return a.exec();
}
