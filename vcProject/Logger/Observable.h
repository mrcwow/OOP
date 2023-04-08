#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

class Observable: public Observer{
    public:
        void notify(string logs){
            update(logs);
        }
};
#endif