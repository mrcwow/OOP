#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "Cell.h"

class Entrance: public Cell{
    private:
        string condition;
    public:
        Entrance(){
            condition = "i";
            obj.change_object("Empty");
        }
        string get_condition(){
            return condition;
        }
};
#endif