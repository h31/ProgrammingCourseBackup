#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <time.h>
using namespace std;

enum Importance
{
    ERROR = 1,
    INFO = 2,
    DEBUG = 3
};

void log(enum Importance importance, const char *unit_name, const char *message);

#endif // LOGGER_H
