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


private slots:


    void on_pushButton_clicked();

private:
    Ui::firstDialog *ui;
};

#endif // FIRSTDIALOG_H