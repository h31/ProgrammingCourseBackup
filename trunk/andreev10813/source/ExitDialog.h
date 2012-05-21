#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QDialog>
 #include <QLabel>
 #include <QPushButton>
 #include <QHBoxLayout>
 #include <QVBoxLayout>
 class ExitDialog : public QDialog
 {
 Q_OBJECT

 QHBoxLayout hi,lo;
 QVBoxLayout lay;
 QLabel label;
 QPushButton ok,cancel,exit;
 public:
 ExitDialog(QString);

private slots:
 void ok_presed();
 void cancel_presed();
 void exit_presed();
 signals:
 void exits();
 };


#endif // EXITDIALOG_H
