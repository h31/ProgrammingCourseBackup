#ifndef TESTSVARIANTS_H
#define TESTSVARIANTS_H

#include <QDialog>

namespace Ui {
class testsVariants;
}

class testsVariants : public QDialog
{
    Q_OBJECT
    
public:
    explicit testsVariants(QWidget *parent = 0);
    ~testsVariants();
    int getTypeOfTest();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::testsVariants *ui;
    int typeOfTest;
};

#endif // TESTSVARIANTS_H
