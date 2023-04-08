#include "Builder.h"
#include "Creature.h"
#include "Player.h"

Builder::Builder(int n, int m): n(n), m(m){}

Field Builder::fill_Field(){
    Field field(n, m);
    srand(time(0));
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m-1; j++){
            field.arr[i][j].change_condition(to_string(rand() %2));
        }
    }
    for (int i = 0; i < m; i ++) field.arr[0][i].change_condition("0");
    for (int i = 0; i < n; i ++) field.arr[i][0].change_condition("0");
    for (int i = 0; i < n; i ++) field.arr[i][m-1].change_condition("0");
    Entrance i;
    field.arr[rand() %n][0] = i;
    Exit e;
    Player* hero = new Player();
    field.arr[0][0].put_game_obj(hero);
    field.arr[rand() %n][m-1] = e;
    return field;
}