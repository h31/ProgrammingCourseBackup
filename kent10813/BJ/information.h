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
    void showBets();
private slots:
    void on_pushButton_clicked();

    void on_label_7_linkActivated(const QString &link);

    void on_label_linkActivated(const QString &link);

    void on_label_4_linkActivated(const QString &link);

    void on_label_6_linkActivated(const QString &link);

private:
    Ui::information *ui;
    Game *gm;
    RealPlayer *pl;
    Dealer *dealer;
    //firstDialog dial;
};

#endif // INFORMATION_H

