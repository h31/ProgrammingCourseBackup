#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <condition_variable>
#include <list>
#include "shared.h"

using namespace std;

class Dispatcher
{
public:
    void operator()(ReceiverArgs input, SenderArgs output, list<Directions>* directions, mutex* mutexVariable);
private:
    string html2txt(string html);
};


#endif // DISPATCHER_H
