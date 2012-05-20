#include <QtGui/QApplication>
#include "mainwindow.h"
#include "want_to_play.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow win;
    want_to_play play;
    play.show();


    return a.exec();
}
