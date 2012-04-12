#ifndef SHARED_H
#define SHARED_H

#include <string>
#include <time.h>

using namespace std;

class HTTPClientException {};
class HTTPServerException {};
class XMLParserException {};

class AddressCorrectnessException {};

enum Importance
{
    ERROR = 1,
    INFO = 2,
    DEBUG = 3
};

void log(enum Importance importance, const char *unit_name, const char *message);

#endif // SHARED_H
