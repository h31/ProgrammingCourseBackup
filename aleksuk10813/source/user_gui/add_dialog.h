#ifndef ADD_DIALOG_H
#define ADD_DIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();
    QString address;
    QString protocol;
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddDialog *ui;
};

#endif // ADD_DIALOG_H
