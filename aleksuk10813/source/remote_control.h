#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <condition_variable>
#include <mutex>
#include <string>
#include <set>

using namespace std;

class RemoteControl
{
public:
    void operator()(set<string>& sources,
                    condition_variable& cond,
                    mutex& m);
};

#endif // REMOTE_CONTROL_H
