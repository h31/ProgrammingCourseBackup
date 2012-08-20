#ifndef STATISTICS_H
#define STATISTICS_H
#include "QFile"
#include "QTextStream"
#include "QString"

class Statistics
{
    QString games;
    QString wins;
    QString loses;
    double dgames,dwins,dloses;
    QString winpercent,losepercent;
    double winper,loseper;
public:
    Statistics();
    void readStatistics();
    void writeStatistics();
    QString getGames();
    QString getWins();
    QString getLoses();
    QString getWinPer();
    QString getLosePer();
    double getDGames();
    double getDWins();
    double getDLoses();
    double getDWinPer();
    double getDLosePer();
    void setGames(int num);
    void setWins(int num);
    void setLoses(int num);
    void setWinPer(int num);
    void setLosePer(int num);
};

#endif // STATISTICS_H
