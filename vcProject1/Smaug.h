#ifndef ENEMY_SMAUG_H
#define ENEMY_SMAUG_H

#include "Creature.h"
#include "Weapon.h"
#include "Armor.h"

class Smaug: public Creature{
    public:
        Smaug(): Creature(500, new Weapon(50), new Armor(50)) {}
};
#endif 