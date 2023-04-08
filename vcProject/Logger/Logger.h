#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
using namespace std;

class Logger{
    protected:
        string info_begin;
        string info_end;
    public:
        Logger(string info_begin = "", string info_end = ""): info_begin(info_begin), info_end(info_end) {}

        virtual void log(string logs) = 0;

        Logger & operator<<(string logs){
            log(logs);
            return *this; 
        }
};
#endif 