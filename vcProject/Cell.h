#ifndef CELL_H
#define CELL_H

#include "Interface_cell.h"
#include "Creature.h"
#include "Items.h"
#include "Player.h"
#include "Bolg.h"
#include "Smaug.h"
#include "Nazgul.h"
#include "Weapon.h"
#include "Armor.h"
#include "Medicine.h"

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
            if (!object){
                this->object = other;
                return true;
            }
            else if (dynamic_cast<Items*>(object)){
                object->interact((dynamic_cast<Creature*>(other)));
                object = other;
                return true;
            }
            else{
                if (!other->interact((dynamic_cast<Creature*>(object)))){
                    delete object;
                    object = other;
                    return true;
                }
                if (!object->interact((dynamic_cast<Creature*>(other)))){
                    delete other;
                    return true;
                }
            }
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

        bool player(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Player)){
                return true;
            }
            return false;
        }

        bool bolg(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Bolg)){
                return true;
            }
            return false;
        }

        bool smaug(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Smaug)){
                return true;
            }
            return false;
        }

        bool nazgul(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Nazgul)){
                return true;
            }
            return false;
        }

        bool weapon(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Weapon)){
                return true;
            }
            return false;
        }

        bool armor(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Armor)){
                return true;
            }
            return false;
        }

        bool medicine(){
            if (object && typeid(*this->get_objectofgame()) == typeid(Medicine)){
                return true;
            }
            return false;
        }

        bool entrance(){
            if (condition == "i "){
                return true;
            }
            return false;
        }

        bool exit(){
            if (condition == "e "){
                return true;
            }
            return false;
        }

        bool wall(){
            if (condition == "1 "){
                return true;
            }
            return false;
        }

        Object_of_game* get_objectofgame(){
            return object;
        }
};
#endif