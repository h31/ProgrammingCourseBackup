#ifndef FINALRESULTS_H
#define FINALRESULTS_H

#include <QtGui>

class FinalResults : public QDialog
{
    Q_OBJECT
public:
    FinalResults(int newscore,QWidget *parent);
protected:
    virtual void paintEvent(QPaintEvent *);
    QLineEdit *Editname;
    QPushButton *ButtonCommit;

    public slots:
    void oncommitname();
public:
    bool SaveToFile();
    int score;
};



#endif // FINALRESULTS_H
