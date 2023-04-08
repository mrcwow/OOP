#ifndef CELLN_H
#define CELLN_H

#include "Cell.h"

class Celln{
    public:
        bool player;
        bool bolg;
        bool smaug;
        bool nazgul;
        bool medicine;
        bool weapon;
        bool armor;
        bool entrance;
        bool exit;
        bool wall;
        int hp; 
        int dmg; 
        int armor_v;
        int value;

        Celln(){}

        Celln(Cell* cell){
            this->player = cell->player();
            this->bolg = cell->bolg();
            this->smaug = cell->smaug();
            this->nazgul = cell->nazgul();
            this->medicine = cell->medicine();
            this->weapon = cell->weapon();
            this->armor = cell->armor();

            if (cell->entrance()){
                this->wall = false;
                this->exit = false;
                this->entrance = true;
            }

            if (cell->exit()){
                this->wall = false;
                this->exit = true;
                this->entrance = false;
            }

            if (cell->wall()){
                this->wall = true;
                this->exit = false;
                this->entrance = false;
            }
            
            if(this->player || this->bolg || this->smaug || this->nazgul){
                this->hp = dynamic_cast<Creature*>(cell->get_objectofgame())->get_hp();
                this->dmg = dynamic_cast<Creature*>(cell->get_objectofgame())->get_weapon();
                this->armor_v = dynamic_cast<Creature*>(cell->get_objectofgame())->get_armor();
            }
            else if (this->medicine){
                this->value = dynamic_cast<Medicine*>(cell->get_objectofgame())->get_healsize();
            }
            else if (this->weapon){
                this->value = dynamic_cast<Weapon*>(cell->get_objectofgame())->get_dmg();
            }
            else if (this->armor){
                this->value = dynamic_cast<Armor*>(cell->get_objectofgame())->get_value();
            }
        }
};
#endif