#include "field_View.h"

void field_View::print_F(Field object){
    Field field_for_print = object;
    for (int i = 0; i < field_for_print.n; i++){
        for (int j = 0; j < field_for_print.m; j++){
            //cout << field_for_print.arr[i][j].get_condition();
            if (field_for_print.arr[i][j].get_objectofgame()){
                cout << print[typeid(*field_for_print.arr[i][j].get_objectofgame()).hash_code()];
            }
            else{
                if (field_for_print.arr[i][j].get_condition() == "i " || field_for_print.arr[i][j].get_condition() == "e "){
                    cout << field_for_print.arr[i][j].get_condition();
                }
                else{
                    cout << print[typeid(field_for_print.arr[i][j]).hash_code()];
                }
                //cout << print[typeid(field_for_print.arr[i][j]).hash_code()];
                //cout << field_for_print.arr[i][j].get_condition();
            }
            //cout << typeid(field_for_print.arr[i][j]).name();
        }
        cout << endl;
    }
}