#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QWidget>

namespace Ui {
class WinDialog;
}

class WinDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit WinDialog(QWidget *parent = 0);
    ~WinDialog();
    
protected:
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_H
