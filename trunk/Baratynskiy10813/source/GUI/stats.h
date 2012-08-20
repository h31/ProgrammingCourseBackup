#ifndef STATS_H
#define STATS_H

#include <QWidget>
#include "QLabel"

namespace Ui {
class Stats;
}

class Stats : public QWidget
{
    Q_OBJECT
    
public:
    explicit Stats(QWidget *parent = 0);
    ~Stats();
    QLabel *returnGames();
    QLabel *returnWins();
    QLabel *returnLoses();
    QLabel *returnWinPercent();
    QLabel *returnLosePercent();
    
private:
    Ui::Stats *ui;
};

#endif // STATS_H
