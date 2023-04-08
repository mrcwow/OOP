#include "Builder.h"

class field_View{  
    public:
        field_View(){}
        void print_F(Field object){
            Field field_for_print = object;
            for (int i = 0; i < field_for_print.n; i++){
                for (int j = 0; j < field_for_print.m; j++){
                    cout << field_for_print.arr[i][j].get_condition();
                }
                cout << endl;
            }
        }
};

int main(){
    Builder field_gen(5, 5);
    //field_gen.fill_Field().print_Field();
    Field field = field_gen.fill_Field();
    field_View f;
    f.print_F(field);
    return 0;
}