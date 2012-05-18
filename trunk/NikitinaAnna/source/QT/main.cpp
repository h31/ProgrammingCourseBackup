#include <QtGui/QApplication>
//#include "mainwidget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWidget w;
  w.show();*/
    MainWindow w;
    w.show();
    w.repaint();
    
    return a.exec();
}
