#include <QtGui/QApplication>
#include "mainwindow.h"
#include "firstdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow win;
    firstDialog dialog;
    dialog.show();
    //win.show();

    return a.exec();
}
