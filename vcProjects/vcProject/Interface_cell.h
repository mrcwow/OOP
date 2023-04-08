#ifndef INTERFACECELL_H
#define INTERFACECELL_H

#include "Object.h"
#include "Object_of_game.h"

class Interface_cell{
    protected:
        Object obj;
        Object_of_game* object;
    public:
        virtual string get_condition(){
        }
        virtual void change_condition(){
        }
        virtual void change_condition(string condit){
        }
        virtual bool set_objectofgame(Object_of_game* other){
        }
        virtual Object_of_game* get_objectofgame(){
        }
};
#endif