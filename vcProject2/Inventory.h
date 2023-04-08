#ifndef Inventory_H
#define Inventory_H

#include "Items.h"

class Inventory{
    int size;
    Items** inv_items;
    public:
        Inventory(int size);

        void append(Items* item);
};
#endif 