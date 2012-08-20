#include "statistics.h"
#include "QDataStream"

Statistics::Statistics()
{
}

void Statistics::readStatistics()
{
    QFile file("c://Hangman/stats.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    in>>games;
    in>>wins;
    in>>loses;
    in>>winpercent;
    in>>losepercent;
    file.close();
}

void Statistics::writeStatistics()
{
    QFile file("c://Hangman/stats.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << dgames;
    out << "\n";
    out << dwins;
    out << "\n";
    out << dloses;
    out << "\n";
    out << winper;
    out << "\n";
    out << loseper;
    file.close();
}

QString Statistics::getGames()
{
    return games;
}

QString Statistics::getWins()
{
    return wins;
}

QString Statistics::getLoses()
{
    return loses;
}

QString Statistics::getWinPer()
{
    return winpercent;
}

QString Statistics::getLosePer()
{
    return losepercent;
}

double Statistics::getDGames()
{
    return dgames;
}

double Statistics::getDWins()
{
    return dwins;
}

double Statistics::getDLoses()
{
    return dloses;
}

double Statistics::getDWinPer()
{
    return winper;
}

double Statistics::getDLosePer()
{
    return loseper;
}

void Statistics::setGames(int num)
{
    dgames = num;
}

void Statistics::setWins(int num)
{
    dwins = num;
}

void Statistics::setLoses(int num)
{
    dloses = num;
}

void Statistics::setWinPer(int num)
{
    winper = num;
}

void Statistics::setLosePer(int num)
{
    loseper = num;
}
