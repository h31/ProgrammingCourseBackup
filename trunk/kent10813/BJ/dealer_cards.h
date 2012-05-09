#ifndef DEALER_CARDS_H
#define DEALER_CARDS_H

#include <QDialog>
#include "information.h"
namespace Ui {
class dealer_cards;
}

class dealer_cards : public QDialog
{
    Q_OBJECT
    
public:
    explicit dealer_cards(QWidget *parent = 0);
    ~dealer_cards();
    void paintEvent(QPaintEvent *ev);
private slots:
    void on_pushButton_clicked();

private:
    Ui::dealer_cards *ui;
    QPainter qp;
    QImage image;
};

#endif // DEALER_CARDS_H
