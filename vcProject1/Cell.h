#ifndef CELL_H
#define CELL_H

#include "Interface_cell.h"

class Cell: public Interface_cell{ 
    private:
        string condition;
    public:
        Cell(){
            condition = "0";
            //obj.change_object("Empty");
        }

        bool put_game_obj(Obj_of_game* other) override {
            if (!this->Obj) {
                this->Obj = other;
                return true;
            }
        }
        string get_condition(){
            return condition;
        }
        //void change_condition(){
        //    cout << "Ввод состояние клетки: ";
        //    cin >> condition;
        //}
        //void change_condition(string condit){
        //    condition = condit;
        //}
};
#endif