#include "Builder.h"
#include "Player.h"
#include "Bolg.h"
#include "Items.h"
#include "Armor.h"
#include "Medicine.h"
#include "Logger/Logger_file.h"
#include "Logger/Logger_console.h"

Builder::Builder(int n, int m): n(n), m(m){}

Field Builder::fill_Field(){
    Field field(n, m);
    srand(time(0));
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m-1; j++){
            field.arr[i][j].change_condition(to_string(rand() %2) + " ");
        }
    }
    for (int i = 0; i < m; i ++) field.arr[0][i].change_condition("0 ");
    for (int i = 0; i < n; i ++) field.arr[i][0].change_condition("0 ");
    for (int i = 0; i < n; i ++) field.arr[i][m-1].change_condition("0 ");
    Entrance i;
    field.arr[rand() %n][0].change_condition("i ");
    Exit e;
    field.arr[rand() %n][m-1].change_condition("e ");

    Logger_file* F = new Logger_file("Logp.log", "P: ");
    Logger_file* F_b = new Logger_file("Logb.log", "B: ");
    Logger_console* Ft = new Logger_console("P: ");
    Logger_console* Ft_b = new Logger_console("B: ");

    // Player* p = new Player();
    // field.arr[0][0].set_objectofgame(p);
    // field.arr[0][0].change_condition("p1");
    // p->add_observer_choose("both", "P");
    // //p->add_observer(F);
    // //p->add_observer(Ft);
    // Armor* a = new Armor(20);
    // a->interact(p);
    // Medicine* med1 = new Medicine(20);
    // med1->interact(p);

    // Bolg* b = new Bolg();
    // field.arr[0][1].set_objectofgame(b);
    // field.arr[0][1].change_condition("b1");
    // b->add_observer_choose("both", "B");
    // //b->add_observer(F_b);
    // //b->add_observer(Ft_b);
    // p->interact(b);
    // b->interact(p);
    // Medicine med = Medicine(20);
    // med.interact(b);
    // //if (field.arr[0][3].get_objectofgame())
    // //cout << typeid(*field.arr[0][3].get_objectofgame()).name();
    // field.arr[0][0].move_objectofgame(&(field.arr[0][3]));
    // //if (field.arr[0][3].get_objectofgame())
    // //cout << typeid(*field.arr[0][3].get_objectofgame()).name();
    return field;
}