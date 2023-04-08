#ifndef INTERFACECELL_H
#define INTERFACECELL_H

#include "Object.h"
#include "Obj_of_game.h"

class Interface_cell{
    protected:
        Object obj;
        Obj_of_game* Obj = nullptr;
    public:
        virtual bool put_game_obj(Obj_of_game* Obj) = 0;
        virtual string get_condition(){
        }
        virtual void change_condition(){
        }
        virtual void change_condition(string condit){
        }
};
#endif