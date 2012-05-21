#include <QApplication>
#include "MainWidget.h"
#include "mainwindow.h"

 int main(int argc,char**envp)
 {
 QApplication app(argc,envp);
 MainWindow window;
 window.show();
 return app.exec();
 }
