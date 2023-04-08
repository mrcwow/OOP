#ifndef OBSERVER_H
#define OBSERVER_H

#include "Loggers.h"

class Observer: public Loggers{
    public:
        void update(string logs){
            for (auto& a: loggers_l)
                *(a) << logs;
        }
};
#endif