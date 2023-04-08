#ifndef LOGGABLE_H
#define LOGGABLE_H

#include "Loggers.h"

class Loggable: public Loggers{
    public:
        void add_logger(Logger* Logger){
            loggers_l.push_back(Logger);
        }

        void notify(string logs){
            for (auto& a: loggers_l)
                *(a) << logs;
        }
};
#endif 