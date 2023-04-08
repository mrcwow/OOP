#include "Weapon.h"
#include "Armor.h"

Creature::Creature(int max_hp, Armor* actual_armor, Weapon* actual_weapon): actual_hp(max_hp), max_hp(max_hp), 
actual_armor(actual_armor), actual_weapon(actual_weapon) {}

void Creature::set_armor(Armor* armor){
    actual_armor = armor;
}

void Creature::set_weapon(Weapon* weapon){
    actual_weapon = weapon;
}

int Creature::get_hp(){
    return actual_hp;
}

int Creature::get_armor(){
    return actual_armor->get_value();
}

int Creature::get_weapon(){
    return actual_weapon->get_dmg();
}

bool Creature::interact(Creature* other){
    cout << "interact creature" << endl;
    // first stage - damage armor
    int armor = other->get_armor();
    int damage = get_weapon();
    int dif = armor - damage;
    // second stage - damage hp
    if (dif >=0){}
    else other->increase_hp(dif);
    return other->actual_hp > 0;
}

void Creature::increase_hp(int hp){
    actual_hp = min(max_hp, actual_hp + hp);
}



