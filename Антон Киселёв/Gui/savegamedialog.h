#ifndef SAVEGAMEDIALOG_H
#define SAVEGAMEDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLayout>
#include <QLabel>
#include "mainwidget.h"

class SaveGameDialog : public QDialog
{
    Q_OBJECT

    QGridLayout *lay;
    QPushButton *save, *cancel;
    
public:
    SaveGameDialog();
    ~SaveGameDialog();

private slots:
    void save_pressed(Field* GameField);
    void cancel_press();
signals:
    void exits();

};

#endif // SAVEGAMEDIALOG_H
