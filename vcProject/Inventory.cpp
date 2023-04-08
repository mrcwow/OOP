#include "Inventory.h"

Inventory::Inventory(int size): size(size){
    // fill empty inventory
    inventory_items = new Items*[size];
    for (int i = 0; i < size; i++){
        inventory_items[i] = nullptr;
    }   
}

void Inventory::selection(Items* item) {
    // Got item
    for (int i = 0; i < size; i++){
        inventory_items[i] = item;
    }
}