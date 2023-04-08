#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>
#include <ctime>
#include "Cell.h"

class Field{
    friend class Builder;
    friend class field_View;
    private:
        void clear();
        void copy(const Field & object);
        void move(Field && object);
    protected:
        
    public:
        int n, m;
        Cell** arr;
        Field(int n_size, int m_size);
        
        Field(const Field& object);
        
        Field & operator=(const Field & object);
        
        Field(Field&& object);
        
        Field & operator=(Field && object);

        void set_objectsofgame(vector<Object_of_game *> obj);
        
        ~Field();
};
#endif