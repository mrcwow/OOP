#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
using namespace std;

class Object{
    private:
        string obj;
    public:
        string get_object();
        void change_object();
        void change_object(string object);
};
#endif