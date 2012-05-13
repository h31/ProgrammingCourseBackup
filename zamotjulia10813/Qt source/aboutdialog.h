#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtGui>
#include <QLabel>

class AboutDialog: public QDialog
{
    Q_OBJECT
    QLabel *label;

protected:
    virtual void paintEvent(QPaintEvent *);
public:
    AboutDialog(QWidget *parent);
    ~AboutDialog();
};

#endif // ABOUTDIALOG_H
