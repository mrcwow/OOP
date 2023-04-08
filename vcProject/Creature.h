#ifndef CREATURE_H
#define CREATURE_H

#include "Object_of_game.h"

class Creature: public Object_of_game{
    private:
        int actual_hp;
        int max_hp;
        Armor* actual_armor;
        Weapon* actual_weapon;
    public:
        Creature(int max_hp, Armor* actual_armor, Weapon* actual_weapon);

        void set_armor(Armor* armor);

        void set_weapon(Weapon* weapon);
        
        int get_hp();

        int get_armor();

        int get_weapon();

        bool interact(Creature* other);

        void increase_hp(int hp);
};
#endif