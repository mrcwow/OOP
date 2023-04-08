#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Weapon.h"
#include "Armor.h"

class Player: public Creature{
    public:
        Player(): Creature(200, new Weapon(30), new Armor(20)) {}
};
#endif 