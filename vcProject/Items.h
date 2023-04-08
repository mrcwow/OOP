#ifndef ITEMS_H
#define ITEMS_H

#include "Object_of_game.h"
#include "Classes_game.h"

class Items: public Object_of_game{
    public:
        bool interact(Creature* obj){
        //interaction with creatures
        return true;
        }
};
#endif