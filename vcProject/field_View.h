#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "Builder.h"
#include <map>
#include "Player.h"
#include "Cell.h"
#include "Bolg.h"
#include "Nazgul.h"
#include "Smaug.h"
#include "Entrance.h"
#include "Armor.h"
#include "Medicine.h"
#include "Weapon.h"

class field_View{
    private:
     map<size_t, string> print = {
            {typeid(Cell).hash_code(), "0 "},
            {typeid(Player).hash_code(), "p "},
            {typeid(Bolg).hash_code(), "b "},
            {typeid(Nazgul).hash_code(), "n"},
            {typeid(Smaug).hash_code(), "s "},
            {typeid(Entrance).hash_code(), "i "},
            {typeid(Armor).hash_code(), "a "},
            {typeid(Medicine).hash_code(), "m "},
            {typeid(Weapon).hash_code(), "w "}
    };
    public:
        field_View(){}
        void print_F(Field object);
};
#endif