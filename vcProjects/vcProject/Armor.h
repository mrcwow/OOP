#ifndef ARMOR_H
#define ARMOR_H

#include "Creature.h"
#include "Items.h"

class Armor: public Items{
    private:
        int value;
    public:
        Armor(int value): value(value){}

        int get_value(){
            return value;
        }
        
        // interaction with the creature
        bool interact(Creature* obj){
            cout << "interact item" << endl;
            obj->set_armor(this);
            return true;
        }       
};
#endif 