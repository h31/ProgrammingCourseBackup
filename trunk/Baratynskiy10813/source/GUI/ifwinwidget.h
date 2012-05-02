#ifndef IFWINWIDGET_H
#define IFWINWIDGET_H

#include <QWidget>
#include "QPushButton"

namespace Ui {
class IfWinWidget;
}

class IfWinWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit IfWinWidget(QWidget *parent = 0);
    ~IfWinWidget();
    Ui::IfWinWidget *ui;
    QPushButton* returnYes();
    QPushButton* returnNo();

private slots:
    void on_yes_clicked();

};

#endif // IFWINWIDGET_H
