#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include "play_again.h"
namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT
    
public:
    explicit information(QWidget *parent = 0);
    ~information();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::information *ui;
};

#endif // INFORMATION_H



