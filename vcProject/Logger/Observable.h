#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

class Observable: public Observer{
    protected:
        
    public:
        //string info;
        //Observable(string info): info(info) {}
        

        void notify(string logs){
            update(logs);
        }
};
#endif