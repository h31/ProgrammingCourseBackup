#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>

#include "play_again.h"
#include "want_to_play.h"
namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT
    
public:
    explicit information(QWidget *parent = 0);
    ~information();
    void showBets();
    int dlrScore();
    int scr;
private slots:
    void on_pushButton_clicked();



private:
    Ui::information *ui;
  //  firstDialog *fd;
    QString money;
   // want_to_play *new_game;
    dealer_cards *dlr_cards;
    void who_won();

};

#endif // INFORMATION_H

