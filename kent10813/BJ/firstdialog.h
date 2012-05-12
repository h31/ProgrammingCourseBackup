#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>
#include "QInputDialog"
#include "mainwindow.h"
namespace Ui {
class firstDialog;
}

class firstDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit firstDialog(QWidget *parent = 0);
    ~firstDialog();

public slots:


    QString on_pushButton_clicked();


    int on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::firstDialog *ui;
};

#endif // FIRSTDIALOG_H
