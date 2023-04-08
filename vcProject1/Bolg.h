#ifndef ENEMY_BOLG_H
#define ENEMY_BOLG_H

#include "Creature.h"
#include "Weapon.h"
#include "Armor.h"

class Bolg: public Creature{
    public:
        Bolg(): Creature(100, new Weapon(15), new Armor(15)) {}
};
#endif 