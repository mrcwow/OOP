#include "Inventory.h"

Inventory::Inventory(int size): size(size){
    inv_items = new Items*[size];
    for (int i = 0; i < size; i++)
        inv_items[i] = nullptr;
}

void Inventory::append(Items* item) {
    for (int i = 0; i < size; i++){
        //check empty slot
        if (!inv_items[i]) inv_items[i] = item;
    }
}