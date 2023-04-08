#ifndef ENEMY_NAZGUL_H
#define ENEMY_NAZGUL_H

#include "Creature.h"
#include "Armor.h"
#include "Weapon.h"

class Nazgul: public Creature{
    public:
        Nazgul(): Creature(200, new Armor(20), new Weapon(20)) {}
        Nazgul(int hp, int armor, int dmg): Creature(hp, new Armor(armor), new Weapon(dmg)) {}
};
#endif 