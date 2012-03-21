#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <time.h>
using namespace std;

enum Importance
{
    FATAL_ERROR = 0,
    SOLVABLE_PROBLEM = 1,
    INFO = 2,
    DEBUG = 3
};

void log(enum Importance importance, char *message);

#endif // LOGGER_H
