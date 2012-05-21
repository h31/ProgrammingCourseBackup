#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include "QtGui"
namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT
    
public:
    explicit information(QWidget *parent = 0);
    ~information();
    QLabel *getLabel();
    QLabel *getLabel2();
    QLabel *getLabel3();
    QLabel *getLabel4();
private slots:
    void on_pushButton_clicked();
private:
    Ui::information *ui;

};

#endif // INFORMATION_H

