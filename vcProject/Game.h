#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H

#include "Rules.h"
#include "Builder.h"
#include "vector"
#include "Bolg.h"
#include "Smaug.h"
#include "Nazgul.h"
#include "Player.h"
#include "Medicine.h"
#include "Weapon.h"
#include "Armor.h"
#include "field_View.h"
#include "Logger/Logger_console.h"
#include "Logger/Logger_file.h"


template <template<int, int> class R, int enemycount, int itemcount>
class Game{
private:
    R<enemycount, itemcount> rule;
    Field f;

    void move_enemies(){
        for (int i = 0; i < f.n; i++){
            for (int j = 0; j < f.m; j++){
                if ((f.arr[i][j].get_objectofgame()) && ((typeid((f.arr[i][j].get_objectofgame())) == typeid(Bolg)) || (typeid((f.arr[i][j].get_objectofgame())) == typeid(Smaug)) || (typeid((f.arr[i][j].get_objectofgame())) == typeid(Nazgul)))){
                    move(i,j);
                }
            }
        }
    }

    bool move(int y, int x){
        if (0 <= y + 1 && y + 1 < f.n) {
            if (f.arr[y][x].move_objectofgame(&(f.arr[y+1][x])))
                return true;
        }

        if (0 <= x + 1 && x + 1 < f.m) {
            if (f.arr[y][x].move_objectofgame(&(f.arr[y][x+1])))
                return true;
        }

        if (0 <= y - 1 && y - 1 < f.n) {
            if (f.arr[y][x].move_objectofgame(&(f.arr[y-1][x])))
                return true;
        }

        if (0 <= x - 1 && x - 1 < f.m) {
            if (f.arr[y][x].move_objectofgame(&(f.arr[y][x-1])))
                return true;
        }

        return false;
    }


public:
    void start(){
        Player* p = new Player();
        p->add_observer_choose("console", "P");
        f.arr[0][0].set_objectofgame(p);

        field_View view_f(f);

        vector<Object_of_game *> enemies;
        vector<Object_of_game *> items;

        switch (enemycount) {
            case 1:
                enemies.push_back(new Bolg);
                break;
            case 2:
                enemies.push_back(new Bolg);
                enemies.push_back(new Smaug);
                break;
            case 3:
                enemies.push_back(new Bolg);
                enemies.push_back(new Smaug);
                enemies.push_back(new Nazgul);
                break;
            default:
                enemies.push_back(new Bolg);
                enemies.push_back(new Smaug);
                for (int i = 3; i < enemycount; i++)
                    enemies.push_back(new Bolg);
        }

        switch (itemcount) {
            case 1:
                items.push_back(new Medicine(20));
                break;
            case 2:
                items.push_back(new Medicine(20));
                items.push_back(new Weapon(10));
                break;
            case 3:
                items.push_back(new Medicine(20));
                items.push_back(new Medicine(20));
                items.push_back(new Weapon(10));
                break;
            default:
                items.push_back(new Armor(20));
                items.push_back(new Weapon(10));
                for (int i = 3; i < itemcount; i++)
                    items.push_back(new Medicine(20));
        }

        f->set_obj(enemies);
        f->set_obj(items);

        while (h->get_hp()>0){
            view_f.print_Field();
            std::cout << "\n";
            //move_enemies();
        }

    }

    void set_field(Field* other){
        f = other;
    }


//    void print(){
//        Field_View view_f(f);
//        view_f.print_Field();
//    }

};

#endif //OOP_GAME_GAME_H