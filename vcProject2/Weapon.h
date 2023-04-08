#ifndef WEAPON_H
#define WEAPON_H

#include "Items.h"
#include "Creature.h"

class Weapon: public Items{
    private:
        int dmg;
    public:
        Weapon(int dmg): dmg(dmg){}
        
        bool interact(Creature *obj){
            //obj->set_weapon(this);
        }

        int get_dmg(){
            return dmg;
        }
};
#endif 