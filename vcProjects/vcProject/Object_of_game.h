#ifndef OBJECT_OF_GAME_H
#define OBJECT_OF_GAME_H

#include <iostream>
#include "Classes_game.h"

class Object_of_game{
    public:
        virtual bool interact(Creature* obj) = 0;
};
#endif 