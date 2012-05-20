#ifndef WANT_TO_PLAY_H
#define WANT_TO_PLAY_H

#include <QDialog>
#include "firstdialog.h"
namespace Ui {
class want_to_play;
}

class want_to_play : public QDialog
{
    Q_OBJECT
    
public:
    explicit want_to_play(QWidget *parent = 0);
    ~want_to_play();
    firstDialog *dialog;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::want_to_play *ui;

};

#endif // WANT_TO_PLAY_H
