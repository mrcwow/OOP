#ifndef MEDICINE_H
#define MEDICINE_H

#include "Creature.h"
#include "Items.h"

class Medicine: public Items{
    private:
        int heal_size;
    public:
        Medicine(int heal_size): heal_size(heal_size) {}

        int get_healsize(){
            return heal_size;
        }

        // interaction with the creature
        bool interact(Creature* obj){
            cout << "interact item" << endl;
            obj->increase_hp(heal_size);
            return true;
        }
};
#endif 