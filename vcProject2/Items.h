#ifndef ITEMS_H
#define ITEMS_H

#include "Obj_of_game.h"
#include "Game_classes.h"

class Items: public Obj_of_game{
    bool interact(Creature* obj){
        cout << "Item interact with Character\n";
        return false;
    }
};
#endif