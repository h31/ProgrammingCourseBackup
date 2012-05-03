#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainwin = new MainWindow;
    mainwin->show();
    return a.exec();
}
