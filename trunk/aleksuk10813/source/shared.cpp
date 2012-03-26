#include "shared.h"
#include <iostream>
#include <stdlib.h>

#ifdef __MINGW32__
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#endif

string enum2string(enum Importance in)
{
    switch (in) {
    case ERROR:
        return "ERROR";
    case INFO:
        return "INFO";
    case DEBUG:
        return "DEBUG";
    }
}

void log(enum Importance importance, const char* unit_name, const char* message)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%d:%.2d:%.2d %s %s: %s\n",
           timeinfo->tm_hour,
           timeinfo->tm_min,
           timeinfo->tm_sec,
           unit_name,
           enum2string(importance).c_str(),
           message);
}
