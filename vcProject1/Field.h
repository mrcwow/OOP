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
        int n, m;
        Cell** arr;
    public:
        Field(int n_size, int m_size);
        
        Field(const Field& object);
        
        Field & operator=(const Field & object);
        
        Field(Field&& object);
        
        Field & operator=(Field && object);
        
        ~Field();
};