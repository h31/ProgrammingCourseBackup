#include <QtGui>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(380, 380);
    w.setWindowTitle("Sunny Seeds");
    w.show();
    QPalette pal;
    pal.setBrush(w.backgroundRole(), QBrush(QPixmap("img2.jpg")));
    w.setPalette(pal);
    w.setAutoFillBackground(true);
    return a.exec();
}
