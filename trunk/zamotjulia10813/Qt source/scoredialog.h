#ifndef SCOREDIALOG_H
#define SCOREDIALOG_H

#include <QtGui>
#include "game.h"
#include "HighScores.h"
#include <QFile>

class ScoreDialog : public QDialog
{
    Q_OBJECT

protected:
    virtual void paintEvent(QPaintEvent *);

 public:
    bool LoadFromFile();
    ScoreDialog(QWidget *parent);
    ~ScoreDialog();
    HighScores Records;
    QLabel *text;
    vector <QString>all;
};

#endif // SCOREDIALOG_H
