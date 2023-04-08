#include "Builder.h"
#include <map>
#include "Player.h"
#include "Cell.h"
#include "Bolg.h"
#include "Nazgul.h"
#include "Smaug.h"
#include "Entrance.h"

class field_View{
    private:
     map<size_t, string> print = {
            {typeid(Cell).hash_code(), "0 "},
            {typeid(Player).hash_code(), "p "},
            {typeid(Bolg).hash_code(), "b "},
            {typeid(Nazgul).hash_code(), "n"},
            {typeid(Smaug).hash_code(), "s "},
            {typeid(Entrance).hash_code(), "i "}
    };
    public:
        field_View(){}
        void print_F(Field object);
};