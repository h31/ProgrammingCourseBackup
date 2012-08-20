#ifndef RUSSTAT_H
#define RUSSTAT_H

#include <QWidget>
#include "QLabel"

namespace Ui {
class RusStat;
}

class RusStat : public QWidget
{
    Q_OBJECT
    
public:
    explicit RusStat(QWidget *parent = 0);
    ~RusStat();
    QLabel *returnGames();
    QLabel *returnWins();
    QLabel *returnLoses();
    QLabel *returnWinPercent();
    QLabel *returnLosePercent();
    
private:
    Ui::RusStat *ui;
};

#endif // RUSSTAT_H
