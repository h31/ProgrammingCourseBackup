#ifndef CREATEGAMEFIELD_H
#define CREATEGAMEFIELD_H

#include <QDialog>
 #include <QSpinBox>
 #include <QPushButton>
 #include <QLabel>
 #include <QHBoxLayout>
 #include <QVBoxLayout>

class CreateMineField : public QDialog
 {
 Q_OBJECT
 QSpinBox sa,sb,sc;
 QLabel la,lb,lc;
 QPushButton ok,cancel;
 QHBoxLayout hi,lo;
 QVBoxLayout layout;

public:
 CreateMineField();
 private slots:
 void ok_presed();
 void cancel_presed();
 signals:
 void acepted (int,int,int);
 };


#endif // CREATEGAMEFIELD_H
