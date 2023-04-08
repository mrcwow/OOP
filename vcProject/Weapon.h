#ifndef WEAPON_H
#define WEAPON_H

#include "Creature.h"
#include "Items.h"

class Weapon: public Items{
    private:
        int dmg;
    public:
        Weapon(int dmg): dmg(dmg){}
        
        int get_dmg(){
            return dmg;
        }
        
        // interaction with the creature
        bool interact(Creature *obj){
            notify("Weapon was picked up!\n");
            obj->set_weapon(this);
            return true;
        }

};
#endif 