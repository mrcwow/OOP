#ifndef OBJ_OF_GAME_H
#define OBJ_OF_GAME_H

#include <iostream>
#include "Game_classes.h"

class Obj_of_game{
    public:
        virtual bool interact(Creature* obj) = 0;
    };
#endif 