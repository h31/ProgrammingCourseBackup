#ifndef RUSLOSEWIDGET_H
#define RUSLOSEWIDGET_H

#include <QWidget>
#include "QPushButton"

namespace Ui {
class RusLoseWidget;
}

class RusLoseWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit RusLoseWidget(QWidget *parent = 0);
    ~RusLoseWidget();
    QPushButton* returnYes();
    QPushButton* returnNo();
    
private slots:
    void on_yes_clicked();

private:
    Ui::RusLoseWidget *ui;
};

#endif // RUSLOSEWIDGET_H
