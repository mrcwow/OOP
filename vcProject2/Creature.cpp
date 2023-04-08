#include "Weapon.h"
#include "Armor.h"

Creature::Creature(int max_hp, Weapon* actual_weapon, Armor* actual_armor) : max_hp(max_hp), actual_hp(max_hp), actual_weapon(actual_weapon), actual_armor(actual_armor) {}

bool Creature::interact(Creature *other) {
    cout << "Fight\n";
    int a = (other->get_armor() - get_weapon());
    a = (a < 0) ? a : 0;
    other->increase_hp(a);
    return other->actual_hp > 0;
}

void Creature::increase_hp(int hp) {
    actual_hp = min(max_hp, actual_hp + hp);
}

void Creature::set_armor(Armor *armor) {
    actual_armor = armor;
}

void Creature::set_weapon(Weapon *weapon) {
    actual_weapon = weapon;
}

int Creature::get_hp() {
    return actual_hp;
}

int Creature::get_armor() {
    return actual_armor->get_value();
}

int Creature::get_weapon() {
    return actual_weapon->get_dmg();
}

