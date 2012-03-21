#include "logger.h"
#include <iostream>
#include <stdlib.h>

#ifdef __MINGW32__
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#endif

string enum2string(enum Importance in)
// TODO: для создания оплота Си в отдельно взятом модуле нужно избавиться от string :)
{
    switch (in) {
    case FATAL_ERROR:
        return "FATAL ERROR";
    case SOLVABLE_PROBLEM:
        return "SOLVABLE PROBLEM";
    case INFO:
        return "INFO";
    case DEBUG:
        return "DEBUG";
    }
}

void log(enum Importance importance, char* message)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%d:%.2d:%.2d %s: %s\n",
           timeinfo->tm_hour,
           timeinfo->tm_min,
           timeinfo->tm_sec,
           enum2string(importance).c_str(),
           message);
    if (importance == FATAL_ERROR)
        exit(1);
    if (importance == SOLVABLE_PROBLEM)
        throw (TestException);
}
