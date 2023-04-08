#ifndef LOGGERS_H
#define LOGGERS_H

#include "Logger.h"
#include <vector>

class Loggers{
    protected:
        vector<Logger *> loggers_l;
    public:
        //virtual void add_logger(Logger* Logger) = 0;

        //virtual void notify(string logs) = 0;
};
#endif 