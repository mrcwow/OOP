#include "field_View.h"
#include "Game.h"

int main(){
    //Builder field_gen(10, 10);
    //field_gen.fill_Field().print_Field();
    //Field field = field_gen.fill_Field();
    //field_View f;
    //f.print_F(field);
    //return 0;
    Game<Rules, 1, 1> game;
    Field ff = Builder(10,10).fill_Field();
    Field f(10,10);
    game.set_fieldofgame(&ff);
    game.start();
}