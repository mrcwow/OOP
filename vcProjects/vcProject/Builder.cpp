#include "Builder.h"
#include "Player.h"
#include "Bolg.h"
#include "Medicine.h"

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
    field.arr[rand() %n][0].change_condition("i");
    Exit e;
    field.arr[rand() %n][m-1].change_condition("e");

    Player* p = new Player();
    cout << "Hp player: " << p->get_hp() << " Armor player: " << p->get_armor() << " Damage player: " << p->get_weapon() << endl;
    field.arr[0][0].set_objectofgame(p);
    field.arr[0][0].change_condition("p");
    Bolg* b = new Bolg();
    cout << "Armor Bolg: " << b->get_armor() << " Hp Bolg: " << b->get_hp() << endl;
    field.arr[0][1].set_objectofgame(b);
    field.arr[0][1].change_condition("b");
    cout << "Did he survive?" << endl;
    if (p->interact(b)){
        cout << "Yes!" << endl;
        cout << "Hp Bolg: " << b->get_hp() << endl;
    }
    else{
        cout << "No!" << endl;
    }
    cout << "Bolg need medicine!" << endl;
    Medicine med = Medicine(20);
    cout << "Hp in medicine: " << med.get_healsize() << endl;
    med.interact(b);
    cout << "Bolg got medicine and his Hp: " << b->get_hp() << endl;
    return field;
}