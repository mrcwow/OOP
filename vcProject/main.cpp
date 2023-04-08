#include "field_View.h"

int main(){
    Builder field_gen(10, 10);
    //field_gen.fill_Field().print_Field();
    Field field = field_gen.fill_Field();
    field_View f;
    f.print_F(field);
    return 0;
}