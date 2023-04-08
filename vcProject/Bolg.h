#ifndef ENEMY_BOLG_H
#define ENEMY_BOLG_H

#include "Creature.h"
#include "Armor.h"
#include "Weapon.h"

class Bolg: public Creature{
    public:
        Bolg(): Creature(100, new Armor(15), new Weapon(15)) {}
        Bolg(int hp, int armor, int dmg): Creature(hp, new Armor(armor), new Weapon(dmg)) {}
};
#endif 