#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Armor.h"
#include "Weapon.h"

class Player: public Creature{
    public:
        Player(): Creature(200, new Armor(20), new Weapon(30)) {}
};
#endif 