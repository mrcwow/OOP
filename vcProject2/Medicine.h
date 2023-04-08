#ifndef MEDICINE_H
#define MEDICINE_H

#include "Items.h"
#include "Creature.h"

class Medicine: public Items{
    private:
        int heal_size;
    public:
        Medicine(int heal_size): heal_size(heal_size) {}

        bool interact(Creature* obj){
            obj->increase_hp(heal_size);
            return true;
        }
};
#endif 