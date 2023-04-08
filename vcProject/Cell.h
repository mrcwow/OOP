#ifndef CELL_H
#define CELL_H

#include "Interface_cell.h"

class Cell: public Interface_cell{ 
    private:
        string condition;
    public:
        Cell(){
            condition = "0";
            obj.change_object("Empty");
        }
        
        string get_condition(){
            return condition;
        }
        void change_condition(){
            cout << "Ввод состояние клетки: ";
            cin >> condition;
        }
        void change_condition(string condit){
            condition = condit;
        }
        
        bool set_objectofgame(Object_of_game* other){
            this->object = other;
            return true;
        }

        bool move_objectofgame(Cell* other){
            if (object && other->set_objectofgame(object)){
                object = nullptr;
                return true;
            }
            else{
                return false;
            }
        }

        Object_of_game* get_objectofgame(){
            return object;
        }
};
#endif