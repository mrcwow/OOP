#ifndef INVENTORY_H
#define INVENTORY_H

#include "Items.h"

class Inventory{
    private:
        int size;
        Items** inventory_items;
    public:
        Inventory(int size);

        void selection(Items* item);
};
#endif 