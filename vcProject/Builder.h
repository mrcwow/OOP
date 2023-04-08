#ifndef BUILDER_H
#define BUILDER_H

#include "Field.h"
#include "Entrance.h"
#include "Exit.h"

class Builder{
    private:
        int n;
        int m;
    public:
        Builder(int n, int m);
        Field fill_Field();
};
#endif