#ifndef ARMOR_H
#define ARMOR_H

#include "Items.h"
#include "Creature.h"

class Armor: public Items{
    private:
        int value;
    public:
        Armor(int value = 0): value(value){}

        bool interact(Creature *obj){
            obj->set_armor(this);
        }

        int get_value(){
            return value;
        }
};
#endif 