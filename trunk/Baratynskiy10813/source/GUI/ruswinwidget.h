#ifndef RUSWINWIDGET_H
#define RUSWINWIDGET_H

#include <QWidget>
#include "QPushButton"

namespace Ui {
class RusWinWidget;
}

class RusWinWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit RusWinWidget(QWidget *parent = 0);
    ~RusWinWidget();
    QPushButton* returnYes();
    QPushButton* returnNo();

private slots:
    void on_yes_clicked();

private:
    Ui::RusWinWidget *ui;
};

#endif // RUSWINWIDGET_H
