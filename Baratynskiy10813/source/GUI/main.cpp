#include <QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *widget= new Widget;
    widget->play();
    return a.exec();
}
