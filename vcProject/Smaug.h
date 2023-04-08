#ifndef ENEMY_SMAUG_H
#define ENEMY_SMAUG_H

#include "Creature.h"
#include "Armor.h"
#include "Weapon.h"

class Smaug: public Creature{
    public:
        Smaug(): Creature(500, new Armor(50), new Weapon(50)) {}
};
#endif 