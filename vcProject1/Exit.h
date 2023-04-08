#include "Cell.h"

class Exit: public Cell{
    private:
        string condition;
    public:
        Exit(){
            condition = "e";
            //obj.change_object("Empty");
        }
        string get_condition(){
            return condition;
        }
};