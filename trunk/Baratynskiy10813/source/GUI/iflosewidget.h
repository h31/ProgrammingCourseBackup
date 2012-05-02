#ifndef IFLOSEWIDGET_H
#define IFLOSEWIDGET_H

#include <QWidget>
#include "QPushButton"

namespace Ui {
class IfLoseWidget;
}

class IfLoseWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit IfLoseWidget(QWidget *parent = 0);
    ~IfLoseWidget();
     Ui::IfLoseWidget *ui;
     QPushButton* returnYes();
     QPushButton* returnNo();
private slots:
    void on_yes_clicked();
};

#endif // IFLOSEWIDGET_H
