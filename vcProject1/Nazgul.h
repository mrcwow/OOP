#ifndef ENEMY_NAZGUL_H
#define ENEMY_NAZGUL_H

#include "Creature.h"
#include "Weapon.h"
#include "Armor.h"

class Nazgul: public Creature{
    public:
        Nazgul(): Creature(200, new Weapon(20), new Armor(20)) {}
};
#endif 