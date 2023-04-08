#ifndef CREATURE_H
#define CREATURE_H

#include "Obj_of_game.h"

class Creature: public Obj_of_game{
    private:
        int max_hp;
        int actual_hp;
        Armor* actual_armor;
        Weapon* actual_weapon;
    public:
        Creature(int max_hp, Weapon* actual_weapon = nullptr, Armor* actual_armor = nullptr);

        bool interact(Creature* other);

        void increase_hp(int hp);

        void set_armor(Armor* armor);

        void set_weapon(Weapon* weapon);
        
        int get_hp();

        int get_armor();

        int get_weapon();
};
#endif