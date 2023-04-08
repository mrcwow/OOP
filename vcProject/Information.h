#ifndef INFORMATION_H
#define INFORMATION_H

#include <fstream>
#include "Celln.h"
#include "Fieldn.h"

class Information{
    private:
        Field* field;
        Celln*** celln;
        Fieldn* fieldn;
        string c_name = "cellnf.txt";
        string f_name = "fieldnf.txt";
    public:
        Information(Field* field): field(field){}

        void writeCells(){
            ofstream f(c_name, ios::binary);

            celln = new Celln** [field->n];
            for(int i = 0; i < field->n; i++){
                celln[i] = new Celln* [field->m];
                for(int j = 0; j < field->m; j++){
                    celln[i][j] = new Celln(&(field->arr[i][j]));
                }
            }
            bool p, b, s, n, medicine, weapon, armor, entrance, exit, wall;

            int hp, dmg, armor_v, value;

            for(int i = 0; i < field->m; i++){
                for(int j = 0; j < field->n; j++){
                    p = celln[i][j]->player;
                    b = celln[i][j]->bolg;
                    s = celln[i][j]->smaug;
                    n = celln[i][j]->nazgul;
                    medicine = celln[i][j]->medicine;
                    armor = celln[i][j]->armor;
                    weapon = celln[i][j]->weapon;
                    hp = celln[i][j]->hp;
                    dmg = celln[i][j]->dmg;
                    armor_v = celln[i][j]->armor_v;
                    value = celln[i][j]->value;
                    entrance = celln[i][j]->entrance;
                    exit = celln[i][j]->exit;
                    wall = celln[i][j]->wall;
                    f.write(reinterpret_cast<const char *>(&entrance), sizeof(entrance));
                    f.write(reinterpret_cast<const char *>(&exit), sizeof(exit));
                    f.write(reinterpret_cast<const char *>(&wall), sizeof(wall));
                    f.write(reinterpret_cast<const char *>(&p), sizeof(p));
                    f.write(reinterpret_cast<const char *>(&b), sizeof(b));
                    f.write(reinterpret_cast<const char *>(&s), sizeof(s));
                    f.write(reinterpret_cast<const char *>(&n), sizeof(n));
                    f.write(reinterpret_cast<const char *>(&medicine), sizeof(medicine));
                    f.write(reinterpret_cast<const char *>(&weapon), sizeof(weapon));
                    f.write(reinterpret_cast<const char *>(&armor), sizeof(armor));
                    f.write(reinterpret_cast<const char *>(&hp), sizeof(hp));
                    f.write(reinterpret_cast<const char *>(&dmg), sizeof(dmg));
                    f.write(reinterpret_cast<const char *>(&armor_v), sizeof(armor_v));
                    f.write(reinterpret_cast<const char *>(&value), sizeof(value));
                }
            }
            f.close();
        }

        Celln*** readCells(){
            ifstream f(c_name, ios::binary);
            if(!f.is_open())
                throw "Read file is error!";

            celln = new Celln** [field->n];
            for(int i = 0; i < field->n; i++){
                celln[i] = new Celln* [field->m];
                for(int j = 0; j < field->m; j++){
                    celln[i][j] = new Celln();
                }
            }

            for(int i = 0; i < field->n; i++){
                for(int j = 0; j < field->m; j++){
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->entrance)), sizeof(celln[i][j]->entrance));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->exit)), sizeof(celln[i][j]->exit));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->wall)), sizeof(celln[i][j]->wall));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->player)), sizeof(celln[i][j]->player));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->bolg)), sizeof(celln[i][j]->bolg));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->smaug)), sizeof(celln[i][j]->smaug));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->nazgul)), sizeof(celln[i][j]->nazgul));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->medicine)), sizeof(celln[i][j]->medicine));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->weapon)), sizeof(celln[i][j]->weapon));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->armor)), sizeof(celln[i][j]->armor));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->hp)), sizeof(celln[i][j]->hp));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->dmg)), sizeof(celln[i][j]->dmg));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->armor_v)), sizeof(celln[i][j]->armor_v));
                    f.read(const_cast<char *>(reinterpret_cast<const char *>(&celln[i][j]->value)), sizeof(celln[i][j]->value));
                }
            }
            f.close();
            return celln;
        }

        void writeField(){
            ofstream f(f_name, ios::binary);

            fieldn = new Fieldn(field->m, field->n);

            int x;
            int y;
            x = fieldn->x;
            y = fieldn->y;
            f.write(reinterpret_cast<const char *>(&x), sizeof(x));
            f.write(reinterpret_cast<const char *>(&y), sizeof(y));
            f.close();
        }

        Fieldn* readField(){
            ifstream f(f_name, ios::binary);
            if(!f.is_open())
                throw "Read file is error!";

            fieldn = new Fieldn();
            f.read(const_cast<char *>(reinterpret_cast<const char *>(&fieldn->x)), sizeof(fieldn->x));
            f.read(const_cast<char *>(reinterpret_cast<const char *>(&fieldn->y)), sizeof(fieldn->y));
            f.close();
            return fieldn;
        }
};
#endif