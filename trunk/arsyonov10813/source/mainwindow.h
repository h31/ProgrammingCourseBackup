#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Field.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GameFieldQ* field;
    void keyPressEvent(QKeyEvent *event);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
