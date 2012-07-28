#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>
#include <iostream>
#include <fstream>

namespace Ui {
class optionDialog;
}

class optionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit optionDialog(QWidget *parent = 0);
    ~optionDialog();
    
private slots:
    void on_buttonBox_accepted();
    void on_pushButton_clicked();

signals:
    void changesAccepted();

private:
    Ui::optionDialog *ui;
};

#endif // OPTIONDIALOG_H
