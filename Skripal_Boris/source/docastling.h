#ifndef DOCASTLING_H
#define DOCASTLING_H

#include <QDialog>

namespace Ui {
class docastling;
}

class docastling : public QDialog
{
    Q_OBJECT
    
public:
    explicit docastling(QWidget *parent = 0);
    ~docastling();
    bool getDoCastling();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::docastling *ui;
    bool doCastling;
};

#endif // DOCASTLING_H
