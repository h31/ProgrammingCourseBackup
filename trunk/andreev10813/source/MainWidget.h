#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
 #include <QHBoxLayout>
 #include <QVBoxLayout>

 #include "Tgbutton.h"

class MainWidget : public QWidget
 {
 Q_OBJECT

private:
 int r,pr,comp;
 int **mat;
 TGbutton **fields;
 QHBoxLayout *rows;
 QVBoxLayout *cols;
 public:
 MainWidget(int row=10,int col=10,int mines=10);
 ~MainWidget();

 public slots:
 void check();//��������� �������� �� ������
 signals: //��� �������� ���� � ����������� ������ ������������
 void boom();
 void progress(int);
 void finish();
 };

#endif // MAINWIDGET_H
