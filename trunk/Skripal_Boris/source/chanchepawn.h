#ifndef CHANCHEPAWN_H
#define CHANCHEPAWN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ChanchePawn;
}

class ChanchePawn : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChanchePawn(QWidget *parent = 0);
    ~ChanchePawn();

    int getTypeOfFigure();
private slots:

    void on_buttonBox_accepted();

private:
    Ui::ChanchePawn *ui;
    int typeOfFigure;
};

#endif // CHANCHEPAWN_H
