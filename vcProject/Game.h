#ifndef GAME_H
#define GAME_H

#include "Rules.h"
#include "vector"
#include "field_View.h"
#include "Logger/Logger_console.h"
#include "Logger/Logger_file.h"
#include "ConsoleController.h"
#include "Commands.h"
#include "Coordinates.h"
#include "Information.h"


template <template<int, int> class R, int numberofenemies, int numberofitems>
class Game{
    private:
        R<numberofenemies, numberofitems> rules;
        Field* f;
        Information* info;
        Celln*** celln;
        Fieldn* fieldn;
        
        void move_objectofenemies(){
            vector<Coordinates> Enemy;
            for (int i = 0; i < f->n; i++){
                for (int j = 0; j < f->m; j++){
                    if ((f->arr[i][j].get_objectofgame()) && ((typeid((*f->arr[i][j].get_objectofgame())) == typeid(Bolg)) || (typeid((*f->arr[i][j].get_objectofgame())) == typeid(Smaug)) || (typeid((*f->arr[i][j].get_objectofgame())) == typeid(Nazgul)))){
                        Enemy.push_back(Coordinates(i, j));
                    }
                }
            }
            for (auto a: Enemy){
                move(a);
            }
        }

        bool move(Coordinates en){
            int x = en.x;
            int y = en.y;
            if (y+1 < f->n) {
                if (f->arr[y][x].move_objectofgame(&(f->arr[y+1][x])))
                    return true;
            }
            if (x+1 < f->m) {
                if (f->arr[y][x].move_objectofgame(&(f->arr[y][x+1])))
                    return true;
            }
            if (0 <= y-1) {
                if (f->arr[y][x].move_objectofgame(&(f->arr[y-1][x])))
                    return true;
            }
            if (0 <= x-1) {
                if (f->arr[y][x].move_objectofgame(&(f->arr[y][x-1])))
                    return true;
            }
            return false;
        }

        bool move_player(int& xp, int& yp, Commands control){
            if (control.command == control.UP){
                    if (yp - 1 > -1){
                        if (f->arr[yp][xp].move_objectofgame(&(f->arr[yp-1][xp]))){
                            yp--;
                        }
                    }
                }
                if (control.command == control.DOWN){
                    if (yp + 1 < f->n){
                        if (f->arr[yp][xp].move_objectofgame(&(f->arr[yp+1][xp]))){
                            yp++;
                        }
                    }
                }
                if (control.command == control.LEFT){
                    if (xp - 1 > -1){
                        if (f->arr[yp][xp].move_objectofgame(&(f->arr[yp][xp-1]))){
                            xp--;
                        }
                    }
                }
                if (control.command == control.RIGHT){
                    if (xp + 1 < f->m){
                        if (f->arr[yp][xp].move_objectofgame(&(f->arr[yp][xp+1]))){
                            xp++;
                        }
                    }
                }
        }

        bool load(){
            if (fieldn->x == f->m && fieldn->y == f->n){

            }
            else{
                throw "Field is error!";
            }
            Field ff = Builder(fieldn->y, fieldn->x).fill_Field_info(celln, fieldn);
            cout << ff.n << ff.m << endl;
            int check = 0;
            if (ff.n == f->n && ff.m == f->m){
                check = check + 1;
            }
            for (int i = 0; i < ff.n; i++){
                for (int j = 0; j < ff.m; j++){
                    if (ff.arr[i][j].get_objectofgame() && typeid(*ff.arr[i][j].get_objectofgame()) == typeid(Player)){
                        check++;
                    }
                    if (ff.arr[i][j].get_condition() == "i "){
                        check++;
                    }
                    if (ff.arr[i][j].get_condition() == "e "){
                        check++;
                    }
                }
            }
            if (check == 4){
                *f = ff;
                return true;
            }
            throw "Field is error!";
        }
    public:
        void set_fieldofgame(Field* other){
            f = other;
        }

        void start(){
            vector<Object_of_game *> items;
            vector<Object_of_game *> enemies;

            switch (numberofitems){
                case 1:
                    items.push_back(new Medicine(20));
                    break;
                case 2:
                    items.push_back(new Medicine(20));
                    items.push_back(new Weapon(10));
                    break;
                case 3:
                    items.push_back(new Medicine(20));
                    items.push_back(new Weapon(10));
                    items.push_back(new Armor(20));
                    break;
                default:
                    items.push_back(new Weapon(10));
                    items.push_back(new Armor(20));
                    for (int i = 3; i < numberofitems; i++)
                        items.push_back(new Medicine(20));
            }

            switch (numberofenemies){
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
                    for (int i = 3; i < numberofenemies; i++)
                        enemies.push_back(new Bolg);
            }
            int xp;
            int yp;
            Player* p = new Player();
            for (int i = 0; i < f->n; i++){
                for (int j = 0; j < f->m; j++){
                    if (f->arr[i][j].get_condition() == "i "){
                        p->add_observer_choose("console", "P");
                        f->arr[i][j].set_objectofgame(p);
                        xp = j;
                        yp = i;
                    }
                }
            }
            int x_exit;
            int y_exit;
            for (int i = 0; i < f->n; i++){
                for (int j = 0; j < f->m; j++){
                    if (f->arr[i][j].get_condition() == "e "){
                        x_exit = j;
                        y_exit = i;
                    }
                }
            }
            field_View field_for_view;
            f->set_objectsofgame(items);
            f->set_objectsofgame(enemies);
            info = new Information(f);
            Commands control;
            ConsoleController controller;
            while (!(xp == x_exit && yp == y_exit) && p->get_hp() > 0){
                field_for_view.print_F(*f);
                control.command = controller.get_command();
                move_player(xp, yp, control);
                if (control.command == control.SAVE){
                    info = new Information(f);
                    info->writeCells();
                    info->writeField();
                    cout << "Saved!" << endl;
                }
                if (control.command == control.LOAD){
                    try{
                        fieldn = info->readField();
                        celln = info->readCells();
                        load();
                        for (int i = 0; i < f->n; i++){
                        for (int j = 0; j < f->m; j++){
                            if (f->arr[i][j].get_objectofgame() && typeid(*f->arr[i][j].get_objectofgame()) == typeid(Player)){
                                f->arr[i][j].get_objectofgame()->add_observer_choose("console", "P");
                                xp = j;
                                yp = i;
                                p = dynamic_cast<Player *>(f->arr[i][j].get_objectofgame());
                            }
                        }
                        }
                        cout << "Loaded!" << endl;
                    }
                    catch(char const* error){
                        cerr << error << endl;
                        cout << "Load is incorrect" << endl;
                    }    
                }
                else{
                    move_objectofenemies();
                }
                cout << endl;
            }
        }
};
#endif