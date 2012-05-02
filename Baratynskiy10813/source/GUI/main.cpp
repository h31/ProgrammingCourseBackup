#include <QtGui/QApplication>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget *widget = new MainWidget;
    widget->play();
    return a.exec();
}
