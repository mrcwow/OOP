#include "Object.h"

string Object::get_object(){
    return obj;
}

void Object::change_object(){
    cout << "Ввод объекта на клетку: ";
    cin >> obj;
}

void Object::change_object(string object){
    obj = object;
}